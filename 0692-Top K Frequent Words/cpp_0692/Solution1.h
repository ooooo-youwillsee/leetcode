/**
 * @author ooooo
 * @date 2021/5/20 07:31 
 */

#ifndef CPP_0692__SOLUTION1_H_
#define CPP_0692__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
 public:
	vector<string> topKFrequent(vector<string> &words, int k) {
		unordered_map<string, int> m;
		for (auto &word: words) {
			m[word]++;
		}
		auto fn = [&](const string &s1, const string &s2) constexpr {
			if (m[s1] == m[s2]) {
				return s1 < s2;
			} else {
				return m[s1] < m[s2];
			}
		};
		priority_queue<string, vector<string>, decltype(fn)> pq(fn);
		for (auto &[kk, v]: m) {
			pq.push(kk);
		}

		vector<string> ans;
		while (k) {
			auto x = pq.top();
			pq.pop();
			ans.push_back(x);
		}
		return ans;
	}
};
#endif //CPP_0692__SOLUTION1_H_
