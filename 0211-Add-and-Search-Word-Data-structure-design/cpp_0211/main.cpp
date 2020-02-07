#include <iostream>
#include "Solution1.h"

int main() {
  WordDictionary o;
  o.addWord("bad");
  o.addWord("dad");
  o.addWord("mad");
  cout << o.search("pad") << endl; //  false
  cout << o.search("bad") << endl; // true
  cout << o.search(".ad") << endl; // true
  cout << o.search("b..") << endl; // true

  return 0;
}
