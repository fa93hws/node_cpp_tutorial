'use strict'
const express = require('express');
const app = express();
const bash = require('./callBash.js');
const cpp  =require('./callCpp.js');

const testInt = 12345;
app.get('/',function(req,res){
    res.send('hello world!\r\n');
})

// child_process.exec
app.get('/b0',function(req,res){
    bash.run0(testInt,res);
})
// child_process.spawn
app.get('/b1',function(req,res){
    bash.run1(testInt,res);
})

// call wrapped cpp
app.get('/c0',function(req,res){
    cpp.run0(req,res);
})

app.listen(3000,function(){
    console.log("listen on port:3000")
});