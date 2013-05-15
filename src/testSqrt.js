var math = require('./build/Release/math')

var LEN = 10000000
var a = []
for (var i = 0; i < LEN; ++i) {
  a[i] = Math.random()
}

console.time('sqrt');
for (var i = 0; i < LEN; ++i) {
  a[i] = math.sqrt(a[i])
}
console.timeEnd('sqrt')
