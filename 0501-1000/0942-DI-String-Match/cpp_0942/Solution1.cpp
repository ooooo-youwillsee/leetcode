/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2022/05/09 07:14
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> diStringMatch(string s) {
    int n = s.size();
    vector<int> ans(n + 1);

    int low = 0, high = n;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'I') {
        ans[i] = low++;
      } else {
        ans[i] = high--;
      }
    }
    ans[n] = low;
    return ans;
  }
};