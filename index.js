'use strict'
const express = require('express');
const app = express();
const bash = require('./callBash.js');

app.get('/',function(req,res){
    res.send('hello world!\r\n');
})

app.get('/b0',function(req,res){
    bash.run0(req,res);
})

app.listen(3000,function(){
    console.log("listen on port:3000")
});