/**
 * @author ooooo
 * @date 2020/11/30 17:53 
 */

#ifndef CPP_0767__SOLUTION1_H_
#define CPP_0767__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:

	string reorganizeString(string S) {
		vector<int> vec(26, 0);
		int max_count = 0;
		for (auto &c : S) {
			vec[c - 'a']++;
			max_count = max(max_count, vec[c - 'a']);
		}

		if (max_count > (S.size() + 1) / 2) {
			return "";
		}

		auto f = [&](const char &c1, const char &c2) {
			return vec[c1 - 'a'] < vec[c2 - 'a'];
		};
		priority_queue<char, vector<char>, decltype(f)> q(f);
		for (int i = 0; i < 26; ++i) {
			if (vec[i] > 0) {
				q.push(i + 'a');
			}
		}
		string ans = "";
		while (q.size() > 1) {
			char a = q.top();
			q.pop();
			ans.push_back(a);
			char b = q.top();
			q.pop();
			ans.push_back(b);
			vec[a - 'a']--;
			vec[b - 'a']--;
			if (vec[a - 'a'] > 0) {
				q.push(a);
			}
			if (vec[b - 'a'] > 0) {
				q.push(b);
			}
		}
		if (!q.empty()) {
			ans.push_back(q.top());
			q.pop();
		}
		return ans;
	}
};

#endif //CPP_0767__SOLUTION1_H_
