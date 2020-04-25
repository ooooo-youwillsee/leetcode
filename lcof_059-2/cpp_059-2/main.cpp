#include <iostream>
#include "Solution1.h"

int main() {
  MaxQueue q;
  q.push_back(4);
  q.push_back(2);
  q.push_back(4);
  q.push_back(3);
  cout << q.max_value() << endl;
  q.pop_front();
  cout << q.max_value() << endl;
  q.pop_front();
  cout << q.max_value() << endl;
  q.pop_front();
  cout << q.max_value() << endl;
  return 0;
}
