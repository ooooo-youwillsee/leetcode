/**
 * @author ooooo
 * @date 2021/4/4 08:31 
 */

#ifndef CPP_1807__SOLUTION1_H_
#define CPP_1807__SOLUTION1_H_


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
 public:

	string evaluate(string s, vector<vector<string>> &knowledge) {
		unordered_map<string, string> m;
		for (auto &item: knowledge) {
			m[item[0]] = item[1];
		}

		int n = s.size();
		string ans = "";
		for (int i = 0; i < n; ++i) {
			while (i < n && s[i] != '(') {
				ans += s[i];
				i++;
			}
			i++;
			if (i >= n) break;
			int l = i;
			while (i < n && s[i] != ')') {
				i++;
			}
			string word = s.substr(l, i - l);
			if (m.find(word) == m.end()) {
				ans += "?";
			} else {
				ans += m[word];
			}
		}
		return ans;
	}
};

#endif //CPP_1807__SOLUTION1_H_
