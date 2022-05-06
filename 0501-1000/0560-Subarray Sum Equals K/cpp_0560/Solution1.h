//
// Created by ooooo on 6/2/2021.
//

#ifndef CPP_0560_SOLUTION1_H
#define CPP_0560_SOLUTION1_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> m;
      m[0] = 1;
      int ans = 0;
      int sum = 0;
      for (int num : nums) {
        sum += num;
        if (m.find(sum - k) != m.end()) {
          ans += m[sum - k];
        }
        m[sum]++;
      }
      return ans;
    }
};

#endif //CPP_0560_SOLUTION1_H
