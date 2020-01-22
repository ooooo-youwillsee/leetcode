//
// Created by ooooo on 2020/1/22.
//
#ifndef CPP_1237__CUSTOMFUNCTION_H_
#define CPP_1237__CUSTOMFUNCTION_H_

#include <iostream>
#include <vector>

using namespace std;

class CustomFunction {
 public:
  // Returns f(x, y) for any given positive integers x and y.
  // Note that f(x, y) is increasing with respect to both x and y.
  // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
  int f(int x, int y) {
    return x + y;
  }
};

#endif //CPP_1237__CUSTOMFUNCTION_H_
