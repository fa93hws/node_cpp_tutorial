'use strict'
const path = require('path')
const test = require('./cpp/build/Release/test');
module.exports = {
    run0: function(req,res){        
        const obj = new test.Wrapper(15);
        console.log(obj.getA());
        res.send("123");
    }
}