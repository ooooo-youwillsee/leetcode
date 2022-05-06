/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2021/11/11 07:33
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

  int countVowelSubstrings(string word) {
    int ans = 0;
    int n = word.size();

    for (int i = 0; i < n; i++) {
      if (!s.count(word[i])) {
        continue;
      }

      unordered_set<char> marked;
      int j = i;
      for (; j < n; j++) {
        if (!s.count(word[j])) {
          break;
        }
        marked.insert(word[j]);
        if (marked.size() >= s.size()) {
          ans++;
        }
      }

    }
    return ans;
  }
};

