var async = require('./build/Release/async');
var a = require('./utils').randomArray(1000000);

console.time('asyncSort');
async.sort(a, function (res) {
  console.timeEnd('asyncSort');
  console.log(res.slice(0, 10));
});
