/**
 * @author ooooo
 * @date 2021/1/23 12:45 
 */

#ifndef CPP_1319__SOLUTION1_H_
#define CPP_1319__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	struct UF {
		int n;
		vector<int> p;
		UF(int n) : n(n), p(n) {
			for (int i = 0; i < n; ++i) {
				p[i] = i;
			}
		}

		int find(int i) {
			if (p[i] == i) return i;
			return p[i] = find(p[i]);
		}

		bool connected(int i, int j) {
			int pi = find(i), pj = find(j);
			if (pi == pj) return true;
			return false;
		}

		void connect(int i, int j) {
			int pi = find(i), pj = find(j);
			if (pi == pj) return;
			p[pi] = pj;
			n--;
		}

	};

	int makeConnected(int n, vector<vector<int>> &connections) {
		UF uf(n);
		int idle = 0;
		for (int i = 0; i < connections.size(); ++i) {
			if (uf.connected(connections[i][0], connections[i][1])) {
				idle++;
			} else {
				uf.connect(connections[i][0], connections[i][1]);
			}
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (!uf.connected(0, i)) {
				ans++;
				uf.connect(0, i);
				if (ans > idle) return -1;
			}
		}

		return ans;
	}
};

#endif //CPP_1319__SOLUTION1_H_
