var fs = require('fs')
fs.readFile('text.txt', function (err) {
    if(err) {
        console.log(err);
    }
    setTimeout(() => {
        console.log("Display after 1 second");
    }, 1000);
});
console.log("Start here");
