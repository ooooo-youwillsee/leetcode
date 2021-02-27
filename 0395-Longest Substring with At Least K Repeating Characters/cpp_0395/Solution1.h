/**
 * @author ooooo
 * @date 2021/2/27 10:57 
 */

#ifndef CPP_0395__SOLUTION1_H_
#define CPP_0395__SOLUTION1_H_

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// 滑动窗口
class Solution {
 public:
	int longestSubstring(string s, int k) {
		int n = s.size();
		int ans = 0;
		// 对每一个字符种类进行遍历
		for (int i = 1; i <= 26; ++i) {
			int cnt = 0;
			int l = 0, r = 0;
			int less = 0;
			vector<int> m(26, 0);
			while (r < n) {
				m[s[r] - 'a']++;
				if (m[s[r] - 'a'] == 1) {
					cnt++; // 字符种类数+1
					less++; // 没满足条件的+1
				}
				if (m[s[r] - 'a'] == k) {
					less--;
				}
				while (cnt > i) {
					m[s[l] - 'a']--;
					if (m[s[l] - 'a'] == 0) {
						cnt--;
						less--; // 没有该字符，不需要满足条件
					}
					if (m[s[l] - 'a'] == k - 1) {
						// 又不满足条件了
						less++;
					}
					l++;
				}

				if (less == 0) {
					ans = max(ans, r - l + 1);
				}
				r++;
			}
		}
		return ans;
	}
};

#endif //CPP_0395__SOLUTION1_H_
