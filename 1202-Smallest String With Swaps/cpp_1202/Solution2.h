/**
 * @author ooooo
 * @date 2021/2/13 09:17 
 */

#ifndef CPP_1202__SOLUTION2_H_
#define CPP_1202__SOLUTION2_H_

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

	class UF {
	 public:
		vector<int> p;
		int n;

		UF(int n) : n(n), p(n) {
			for (int i = 0; i < n; ++i) {
				p[i] = i;
			}
		}

		int find(int i) {
			if (p[i] == i) return i;
			return p[i] = find(p[i]);
		}

		int connect(int i, int j) {
			int pi = find(i), pj = find(j);
			if (pi == pj) return pi;
			p[pi] = pj;
			return pj;
		}
	};

	string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
		int sz = s.size();
		UF uf(sz);
		unordered_map<int, priority_queue<char, vector<char>, greater<int>>> m;
		for (auto &pair : pairs) {
			uf.connect(pair[0], pair[1]);
		}

		for (int j = 0; j < s.size(); ++j) {
			int pRoot = uf.find(j);
			m[pRoot].push(s[j]);
		}

		string ans = "";
		for (int i = 0; i < s.size(); ++i) {
			auto &letters = m[uf.find(i)];
			ans += letters.top();
			letters.pop();
		}
		return ans;
	}

};

#endif //CPP_1202__SOLUTION2_H_
