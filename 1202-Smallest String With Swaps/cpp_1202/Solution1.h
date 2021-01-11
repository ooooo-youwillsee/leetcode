/**
 * @author ooooo
 * @date 2021/1/11 09:14 
 */

#ifndef CPP_1202__SOLUTION1_H_
#define CPP_1202__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
 public:
	string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
		int n = s.size();
		vector<int> p(n);
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
		unordered_map<int, priority_queue<char, vector<char>, greater<char>>> map;
		for (int i = 0; i < pairs.size(); ++i) {
			int x = pairs[i][0], y = pairs[i][1];
			connect(p, x, y);
		}

		for (int i = 0; i < n; ++i) {
			int pi = findP(p, i);
			map[pi].push(s[i]);
		}

		string ans = "";
		for (int i = 0; i < n; ++i) {
			int pi = findP(p, i);
			char c = map[pi].top();
			map[pi].pop();
			ans += c;
		}
		return ans;
	}

	int findP(vector<int> &p, int i) {
		if (i == p[i]) return i;
		auto pi = findP(p, p[i]);
		p[i] = pi;
		return pi;
	}

	int connect(vector<int> &p, int i, int j) {
		int pi = findP(p, i), pj = findP(p, j);
		if (pi == pj) return pi;
		p[pi] = pj;
		return pj;
	}

};

#endif //CPP_1202__SOLUTION1_H_
