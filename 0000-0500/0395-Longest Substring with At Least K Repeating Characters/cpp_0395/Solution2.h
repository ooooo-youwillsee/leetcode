/**
 * @author ooooo
 * @date 2021/2/27 11:48 
 */

#ifndef CPP_0395__SOLUTION2_H_
#define CPP_0395__SOLUTION2_H_

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// 分治法
class Solution {
 public:

	int dfs(string &s, int l, int r, int k) {
		if (l > r) return 0;
		int n = r + 1;
		vector<int> m(26, 0);
		for (int i = l; i < n; ++i) {
			m[s[i] - 'a']++;
		}
		char split = '0';
		for (int i = 0; i < 26; ++i) {
			if (m[i] > 0 && m[i] < k) {
				// 这个字符没有k个，以它为分界线
				split = i + 'a';
				break;
			}
		}

		if (split == '0') {
			return r - l + 1;
		}

		int ans = 0;
		int i = l;
		while (i < n) {
			while (i < n && s[i] == split) {
				i++;
			}
			if (i >= n) {
				return 0;
			}

			int j = i;
			while (j < n && s[j] != split) {
				j++;
			}
			ans = max(ans, dfs(s, i, j - 1, k));
			i = j;
		}
		return ans;
	}

	int longestSubstring(string s, int k) {
		return dfs(s, 0, s.size() - 1, k);
	}
};

#endif //CPP_0395__SOLUTION2_H_
