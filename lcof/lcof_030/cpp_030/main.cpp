#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

int main() {
  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout << minStack.min() << endl;  // 返回 -3.
  minStack.pop();
  cout << minStack.top() << endl;  // 返回 0.
  cout << minStack.min() << endl;  // 返回 -2.
  return 0;
}
