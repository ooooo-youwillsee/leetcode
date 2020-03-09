//
// Created by ooooo on 2020/3/9.
//
#ifndef CPP_011__SOLUTION2_H_
#define CPP_011__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * O( log(n) )
 */
class Solution {
 public:

  int line_find(vector<int> &numbers, int l, int r) {
    int ans = INT_MAX;
    for (int i = l; i < r; i++) {
      if (ans > numbers[i]) ans = numbers[i];
    }
    return ans;
  }

  int minArray(vector<int> &numbers) {
    int l = 0, r = numbers.size() - 1;
    if (numbers[l] < numbers[r]) return numbers[0];
    while (l < r - 1) {
      int mid = l + (r - l) / 2;
      // 10, 10, 1, 10, 这种情况线性查找
      if (numbers[mid] == numbers[l] && numbers[mid] == numbers[r]) {
        return line_find(numbers, l, r);
      }
      if (numbers[mid] <= numbers[r]) {
        r = mid;
      } else if (numbers[mid] >= numbers[l]) {
        l = mid;
      }
    }
    return numbers[r];
  }
};

#endif //CPP_011__SOLUTION2_H_
