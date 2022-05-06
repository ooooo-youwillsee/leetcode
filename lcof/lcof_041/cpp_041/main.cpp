#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

int main() {
  MedianFinder finder;
  finder.addNum(1);
  finder.addNum(2);
  cout << finder.findMedian() << endl;
  finder.addNum(3);
  cout << finder.findMedian() << endl;

  return 0;
}
