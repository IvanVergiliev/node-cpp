var async = require('./build/Release/async');
var a = require('./utils').randomArray(10000000);

console.time('asyncSort');
async.sort(a, function (res) {
  console.timeEnd('asyncSort');
});
