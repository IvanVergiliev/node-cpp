setTimeout(function () {
  console.log('1. this function should be executed immediately!');
}, 0);
var j = 0;
for (var i = 0; i < 5e8; ++i) {
  j *= 2;
}
console.log('2. and this should be executed after a while');
