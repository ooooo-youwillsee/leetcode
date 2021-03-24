/**
 * @author ooooo
 * @date 2021/2/26 16:34 
 */

#ifndef CPP_0839__SOLUTION1_H_
#define CPP_0839__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
 public:

	struct UF {
		vector<int> p;
		int n;
		UF(int n) : p(n), n(n) {
			for (int i = 0; i < n; ++i) {
				p[i] = i;
			}
		}

		int find(int i) {
			if (p[i] == i) return i;
			return p[i] = find(p[i]);
		}

		bool connect(int i, int j) {
			int pi = find(i), pj = find(j);
			if (pi == pj) {
				return true;
			}
			p[pi] = pj;
			n--;
			return false;
		}
	};

	int numSimilarGroups(vector<string> &strs) {
		int n = strs.size();
		UF uf(n);
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				int pi = uf.find(i), pj = uf.find(j);
				if (pi == pj) continue;
				if(check(strs[i], strs[j])) {
					uf.connect(i, j);
				}
			}
		}
		return uf.n;
	}

	bool check(string &s1, string &s2) {
		int cnt = 0;
		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] != s2[i]) {
				cnt++;
			}
		}
		return cnt <= 2;
	}
};

#endif //CPP_0839__SOLUTION1_H_
