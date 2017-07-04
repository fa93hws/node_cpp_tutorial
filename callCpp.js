'use strict'
const path = require('path')
module.exports = {
    run0: function(req,res){
        let test = require('./cpp/build/Release/test');
        test.hello('test', function(data) {
            console.log(data);
            res.send(data);
        });
    }
}