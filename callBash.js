'use strict'
const exec = require('child_process').exec;
const spawn = require('child_process').spawn;
const path = require('path')


module.exports = {
    run0: function(testInt,res){
        let cmd = path.join(__dirname, '/cpp/hello.exe')
            + ' ' +testInt;
        exec(cmd, function(error, stdout, stderr) {
            res.send(stdout);
        });
    },
    run1: function(testInt,res){
        const cmd = path.join(__dirname, '/cpp/hello.exe');
        const run = spawn(cmd,[testInt],{
            "shell":true
        });
        let out = "";
        run.stdout.on('data', (data) => {
            out += data + "\r\n";
        });

        run.stderr.on('data', (data) => {

        });

        run.on('close', (code) => {
            res.send(out);
        });
    }
}