#include <iostream>
#include "Solution1.h"

int main() {
  CQueue q;
  cout << q.deleteHead() << endl;
  q.appendTail(5);
  q.appendTail(2);
  cout << q.deleteHead() << endl;
  cout << q.deleteHead() << endl;
  return 0;
}
