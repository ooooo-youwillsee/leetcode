/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2021/11/11 07:36
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

  unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};

  long long countVowels(string word) {
    long long ans = 0;
    int n = word.size();

    for (int i = 0; i < n; i++) {
      if (s.count(word[i])) {
        ans += (long long) (i + 1) * (long long) (n - i);
      }
    }
    return ans;
  }
};

