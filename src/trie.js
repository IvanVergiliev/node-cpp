
var Node = function() {
  this.next = {};
}

Node.prototype.insert = function (word) {
  
}

var Trie = function() {
  this.root = new Node;
}

Trie.prototype.insert = function (word) {
  var node = this.root;
  var i = 0;
  while (i < word.length) {
    var curChar = word.charAt(i);
    if (!node.next.hasOwnProperty(curChar)) {
      node.next[curChar] = new Node;
    }
    node = node.next[curChar];
    i += 1;
  }
}

module.exports = Trie;
