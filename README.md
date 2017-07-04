# node cpp performance test

---

[TOC]

## Useage
### Install
clone it first
```
git clone https://github.com/fa93hws/node_cpp_tutorial.git
cd node_cpp_tutorial
```
install the dependencies then
```
npm install
```

build the cpp code after that
```
make
```

Finally, its runnable by typing
```
node index
```

There are four apis available.

localhost:3000/n0 is using native javascript

localhost:3000/b0 is using child process with exec

localhost:3000/b1 is using child process with spawn

localhost:3000/c0 is using wrapper

### Load test
In order to performe a load test, you need to install some tool first. I am using [loadtest][2] and if you would like to choose the same, you can run the command
```
npm install -g loadtest
```
> loadtest http://localhost:3000/b0 -t 90 -c 30 --rps 240

means to call http://localhost:3000/b0 for 90 seconds with 30 clients and 240 requests per second (which is 8 requests per client per second)

## Background
One of the characteristics of Node.js is single thread. All requests are handled in the main thread and most of the tasks will be distributed to other threads. The advantage of this practice can be found every and will not be discussed here. The disadvantage, obviously, will cause long waiting time when one request occupy 100% CPU resources for a while.

Assume we need to calculate all primes no greater than a certain vlue, [sieve of Eratosthenes][1] will be adopted as the right algorithm. In javascript, it can be implemented as followed
```
let isPrime = new Array(testInt).fill(1);
for (let i=2; i < testInt; i++){
    if (isPrime[i-1]===0) continue;
    let multi = 2;
    while(multi*i <= testInt){
        isPrime[i*multi-1] = 0;
        multi++;
    }
}
// only the number is counted and output(otherwise there are too many numbers)
let numPrimes = 0;
for (let i=0; i < testInt;i++){
    if (isPrime[i]===1)
        numPrimes++;
}
```
if we apply a loading test by the help of this [library][2] and run a light test for 120 requests (94 in reality) per second
> loadtest http://localhost:3000/n0 -t 90 -c 30 --rps 120

The result then will be surprising with a 0.012s on each request averagely.
> INFO Completed requests:  8501
INFO Total errors:        0
INFO Total time:          90.00388448599999 s
INFO Requests per second: 94
INFO Mean latency:        5151.9 ms
INFO 
INFO Percentage of the requests served within a certain time
INFO   50%      3095 ms
INFO   90%      6053 ms
INFO   95%      10120 m
INFO   99%      66495 ms
INFO  100%      66837 ms (longest request)

The problem is obvious that we must to pass this cpu heavy task to some other thread or process. The tool we can use is cpp library.

## Child_process running bash calling cpp
This method will be suitable if you don't have any idea about the interface of the library, you don't care too much about the cpu usage (creating process will be a heavy job) or you are too busy to write a wrapper.
The approach to call child process to run the bash is simple. The following code can easily do the job. (It will call /cpp/hello.exe 123456 if testInt = 123456. The stdout then will be pass to the callback in the exec)
```
const exec = require('child_process').exec
let cmd = path.join(__dirname, '/cpp/hello.exe')
    + ' ' +testInt;
exec(cmd, function(error, stdout, stderr) {
    res.send(stdout);
});
```
The result will be much better than that in native javascript. It is possible to handle 206 requests per second with a close average waiting time.
> INFO Completed requests:  18556
INFO Total errors:        0
INFO Total time:          90.00407294 s
INFO Requests per second: 206
INFO Mean latency:        4589.3 ms
INFO 
INFO Percentage of the requests served within a certain time
INFO   50%      3150 ms
INFO   90%      9376 ms
INFO   95%      17290 ms
INFO   99%      33479 ms
INFO  100%      65439 ms (longest request)

## Call cpp directly by create a wrapper

## Conclusion
  [1]: https://zh.wikipedia.org/wiki/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95
  [2]: https://www.npmjs.com/package/loadtest