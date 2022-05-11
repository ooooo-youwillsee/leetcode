/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/11 19:14
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](const auto &x, const auto &y) {
      return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
    });

    int n = envelopes.size();
    vector<int> nums = {envelopes[0][1]};

    for (int i = 1; i < n; ++i) {
      if (envelopes[i][1] > nums.back()) {
        nums.push_back(envelopes[i][1]);
        continue;
      }

      auto it = lower_bound(nums.begin(), nums.end(), envelopes[i][1]);
      *it = envelopes[i][1];
    }

    return nums.size();
  }
};

