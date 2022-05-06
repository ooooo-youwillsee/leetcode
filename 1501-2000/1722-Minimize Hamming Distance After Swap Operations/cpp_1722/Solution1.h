/**
 * @author ooooo
 * @date 2021/3/9 18:18 
 */

#ifndef CPP_1722__SOLUTION1_H_
#define CPP_1722__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	struct UF {
		int n;
		vector<int> p;

		UF(int n) : n(n), p(n) {
			for (int i = 0; i < p.size(); ++i) {
				p[i] = i;
			}
		}

		int find(int i) {
			if (i == p[i]) return i;
			return p[i] = find(p[i]);
		}

		bool connect(int i, int j) {
			int pi = find(i), pj = find(j);
			if (pi == pj) return true;
			p[pi] = pj;
			return false;
		}
	};

	int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps) {
		int n = source.size();
		UF uf(n);
		for (auto &swap: allowedSwaps) {
			int u = swap[0], v = swap[1];
			uf.connect(u, v);
		}

		unordered_map<int, unordered_set<int>> m;
		for (int i = 0; i < n; ++i) {
			int root = uf.find(i);
			m[root].insert(i);
		}

		int ans = 0;

		for (auto &[k, v]: m) {
			unordered_map<int, int> cnt;
			for (auto j: v) {
				cnt[source[j]]++;
			}
			for (auto j: v) {
				if (cnt[target[j]] > 0) {
					cnt[target[j]]--;
				}else {
					ans++;
				}
			}
		}
		return ans;
	}
};

#endif //CPP_1722__SOLUTION1_H_
