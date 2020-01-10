#include <iostream>
//#include "Solution1.h"
#include "Solution1.h"

void test(string secret, string guess) {
  Solution s;
  cout << s.getHint(secret, guess) << endl;
}

int main() {
  test("1807", "7810"); // 1A3B
  test("1123", "0111");
  test("1122", "2211");
  return 0;
}
