'use strict'
const path = require('path')
const test = require('./cpp_wrap/build/Release/test');
module.exports = {
    run0: function(req,res){
        const out = test.getPrimeUnder();
        res.send(out.toString());
    }
}