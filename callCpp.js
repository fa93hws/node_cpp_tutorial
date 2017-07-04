'use strict'
const path = require('path')
const test = require('./cpp/build/Release/test');
module.exports = {
    run0: function(req,res){
        const out = test.getPrimeUnder();
        console.log(out);
        res.send(out.toString());
    }
}