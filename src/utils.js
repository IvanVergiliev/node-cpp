exports.randomArray = function (length) {
  var res = [];
  for (var i = 0; i < length; ++i) {
    res[i] = Math.random()
  }
  return res;
}
