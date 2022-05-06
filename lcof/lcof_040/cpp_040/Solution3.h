//
// Created by ooooo on 2020/3/25.
//
#ifndef CPP_040__SOLUTION3_H_
#define CPP_040__SOLUTION3_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  int partition(int i, int j, vector<int> &arr) {
    int k = i, item = arr[i];
    for (int p = i + 1; p <= j; ++p) {
      if (arr[p] <= item) {
        k++;
        swap(arr[k], arr[p]);
      }
    }
    swap(arr[k], arr[i]);
    return k;
  }

  vector<int> getLeastNumbers(vector<int> &arr, int k) {
    if (k == 0) return {};
    if (k == arr.size()) return arr;
    int start = 0, end = arr.size() - 1;
    int p = partition(start, end, arr);
    while (p != k) {
      if (p < k) {
        start = p + 1;
      } else {
        end = p - 1;
      }
      p = partition(start, end, arr);
    }
    return vector<int>(arr.begin(), arr.begin() + k);
  }
};

#endif //CPP_040__SOLUTION3_H_
