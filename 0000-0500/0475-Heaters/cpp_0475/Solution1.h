//
// Created by ooooo on 2020/1/19.
//
#ifndef CPP_0475__SOLUTION1_H_
#define CPP_0475__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    vector<int> ans;
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    for (auto house : houses) {
      int left = 0, right = heaters.size() - 1, mid;
      while (left < right) {
        mid = left + (right - left) / 2;
        if (heaters[mid] < house) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      // heaters中的最大值已经小于house，最大距离肯定有 house - heaters[left]
      if (heaters[left] < house) {
        ans.push_back(house - heaters[left]);
      } else if (left) {
        ans.push_back(min(heaters[left] - house, house - heaters[left - 1]));
      } else {
        ans.push_back(heaters[left] - house);
      }
    }

    int res = 0;
    for_each(ans.begin(), ans.end(), [&res](auto x) { res = max(res, x); });
    return res;
  }
};

#endif //CPP_0475__SOLUTION1_H_
