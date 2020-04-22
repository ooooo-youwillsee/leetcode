//
// Created by ooooo on 2020/4/22.
//
#ifndef CPP_062__SOLUTION1_H_
#define CPP_062__SOLUTION1_H_

#include <iostream>
#include <list>

using namespace std;

/**
 * timeout
 */
class Solution {
 public:
  int lastRemaining(int n, int m) {
    list<int> l;
    for (int i = 0; i < n; ++i) {
      l.push_back(i);
    }

    auto begin = l.begin();
    while (l.size() > 1) {
      for (int i = 1; i < m; ++i) {
        begin++;
        if (begin == l.end()) begin = l.begin();
      }

      auto cur = begin;
      //cout << *cur << "->";
      begin++;
      if (begin == l.end()) begin = l.begin();
      l.erase(cur);
    }
    return *l.begin();
  }
};

#endif //CPP_062__SOLUTION1_H_
