var algo = require('./build/Release/algorithm');
var a = require('./utils').randomArray(10000000);

console.time('sort');
algo.sort(a);
console.timeEnd('sort');

