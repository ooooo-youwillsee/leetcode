/**
 * @author ooooo
 * @date 2021/2/28 13:13 
 */

#ifndef CPP_1737__SOLUTION1_H_
#define CPP_1737__SOLUTION1_H_

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <numeric>

using namespace std;

class Solution {

 public:

	int calc(vector<int> &count1, vector<int> &count2) {
		int ans = INT_MAX;
		int prevCount = 0;
		for (int i = 25; i >= 1; --i) {
			int count = count1[i] == 0 ? prevCount : count1[i] + prevCount;
			prevCount = count;
			for (int j = 0; j < i; ++j) {
				count += count2[j];
			}
			ans = min(ans, count);
		}
		return ans;
	}

	int minCharacters(string a, string b) {
		vector<int> count1(26), count2(26);
		unordered_map<char, int> m;
		int maxSameCount = 0;
		for (int i = 0; i < a.size(); ++i) {
			count1[a[i] - 'a']++;
			m[a[i]]++;
			maxSameCount = max(maxSameCount, m[a[i]]);
		}
		for (int i = 0; i < b.size(); ++i) {
			count2[b[i] - 'a']++;
			m[b[i]]++;
			maxSameCount = max(maxSameCount, m[b[i]]);
		}

		int ans = a.size() + b.size();
		ans = min(ans, calc(count1, count2));
		ans = min(ans, calc(count2, count1));
		ans = min(ans, (int) a.size() + (int) b.size() - maxSameCount);
		return ans;
	}

};

#endif //CPP_1737__SOLUTION1_H_
