var a = require('./utils').randomArray(1000000);

console.time('javascriptSort');
a.sort();
console.timeEnd('javascriptSort');

