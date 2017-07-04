'use strict'

module.exports = {
    run: function(testInt,res){
        var t0 = new Date().getTime();
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
        var t1 = new Date().getTime();
        let time= (t1 - t0)/1000;
        global.calTime += time;
        console.log(global.calTime);
        res.send(`There are ${numPrimes} primes under ${testInt}.\r\n Finished in ${time}s.`);
    }
}