#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(vector<string> words) {
  Solution solution;
  cout << solution.longestWord(words) << endl;
}

int main() {
  test({"w", "wo", "wor", "worl", "world"}); // world
  test({"a", "banana", "app", "appl", "ap", "apply", "apple"}); // apple
  test({"a", "app", "appl", "ap", "apply", "apple"}); // apple
  test({"yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y"}); // yodn
  return 0;
}
