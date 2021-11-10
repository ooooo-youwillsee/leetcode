/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2021/11/11 07:42
 */

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
 public:
  int minimizedMaximum(int n, vector<int> &quantities) {
    int l = 1, r = *max_element(quantities.begin(), quantities.end());

    int ans = 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;

      int sum = 0;
      for (auto q: quantities) {
        sum += q % mid == 0 ? q / mid : q / mid + 1;
      }

      if (sum <= n) {
        r = mid - 1;
        ans = mid;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }
};

