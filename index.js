'use strict'
const express = require('express');
const app = express();

app.get('/',function(req,res){
    res.send('hello world!\r\n');
})

app.listen(3000,function(){
    console.log("listen on port:3000")
});