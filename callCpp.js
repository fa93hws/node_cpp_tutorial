'use strict'
const path = require('path')
const test = require('./cpp_wrap/build/Release/test');
module.exports = {
    run0: function(testInt,res){
        const out = test.getPrimeUnder(testInt,function(num,time){
            res.send(`There are ${num} primes under ${testInt}.\r\n Finished in ${time}s.`);
        });
    }
}