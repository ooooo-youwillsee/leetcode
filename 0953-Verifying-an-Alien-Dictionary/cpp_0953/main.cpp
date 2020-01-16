#include <iostream>
#include "Solution1.h"

void test(vector<string> words, string order) {
  Solution solution;
  cout << solution.isAlienSorted(words, order) << endl;
}

int main() {
  test({"hello", "leetcode"}, "hlabcdefgijkmnopqrstuvwxyz");
  test({"word", "world", "row"}, "worldabcefghijkmnpqstuvxyz");
  test({"apple", "app"}, "abcdefghijklmnopqrstuvwxyz");
  test({"kuvp", "q"}, "ngxlkthsjuoqcpavbfdermiywz");
  return 0;
}
