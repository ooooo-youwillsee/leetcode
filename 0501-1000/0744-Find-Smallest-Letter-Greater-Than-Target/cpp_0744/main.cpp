#include <iostream>
#include "Solution1.h"

void test(vector<char> letters, char target) {
  Solution solution;
  cout << solution.nextGreatestLetter(letters, target) << endl;
}

int main() {
  test({'c', 'f', 'j'}, 'a'); // c
  test({'c', 'f', 'j'}, 'c'); // f
  test({'c', 'f', 'j'}, 'd'); // f
  test({'c', 'f', 'j'}, 'g'); // j
  test({'c', 'f', 'j'}, 'j'); // c
  test({'c', 'f', 'j'}, 'k'); // c
  return 0;
}
