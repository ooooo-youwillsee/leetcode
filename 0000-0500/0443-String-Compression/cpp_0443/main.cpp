#include <iostream>
#include "Solution1.h"

void test(vector<char> chars) {
  Solution solution;
  int ans = solution.compress(chars);
  cout << ans << "->";
  for (int i = 0; i < ans; ++i) {
    cout << chars[i] << " ";
  }
  cout << endl;
}

int main() {
  test({'a', 'a', 'b', 'b', 'c', 'c', 'c'});
  test({'a'});
  test({'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'});
  test({'a', 'a', 'a', 'b', 'b', 'a', 'a'});
  return 0;
}
