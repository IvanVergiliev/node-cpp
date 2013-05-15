#include <cstdio>
#include <string>
#include <map>

using namespace std;

struct Node {
  map<char, Node*> next;
  static int count;
  Node() {
    ++count;
  }
};
int Node::count = 0;

struct Trie {
  Node* root;
  Trie(): root(new Node) {}

  void insert(const string& s) {
    Node* node = root;
    for(int i = 0; i < s.size(); ++i) {
      if (node->next.find(s[i]) == node->next.end()) {
        node->next[s[i]] = new Node;
      }
      node = node->next[s[i]];
    }
  }
};

int main() {
  char s[100];
  Trie t;
  for (int i = 0; i < 100000; ++i) {
    for (int j = 0; j < 20; ++j) {
      s[j] = rand() % 128;
    }
    s[20] = 0;
    t.insert(s);
  }
  printf("%d nodes created\n", Node::count);
}
