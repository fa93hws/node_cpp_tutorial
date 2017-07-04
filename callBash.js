'use strict'
const exec = require('child_process').exec;
const path = require('path')

module.exports = {
    run0: function(req,res){
        let cmd = path.join(__dirname, '/cpp/hello.exe')
                + ' 12345789';
                exec(cmd, function(error, stdout, stderr) {
                    res.send(stdout);
        });
    }
}