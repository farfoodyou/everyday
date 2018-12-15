'use strict';

console.log('Hello, world.');

var fs = require('fs');

fs.readFile('./test.txt', 'utf-8', function (err, data) {
    if (err) {
        console.log(err);
    } else {
        console.log(data);
    }
});
console.log("=================");
var data = fs.readFileSync('test.txt', 'utf-8');
console.log(data + 'sync');