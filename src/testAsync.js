var async = require('./build/Release/async');
var a = require('./utils').randomArray(1000000);

console.time('asyncSort');
console.time('afterSort');
setTimeout(function () {
  console.log('after sort');
  console.timeEnd('afterSort');
}, 0);
async.sort(a, function (res) {
  console.timeEnd('asyncSort');
  console.log(res.slice(0, 10));
});
