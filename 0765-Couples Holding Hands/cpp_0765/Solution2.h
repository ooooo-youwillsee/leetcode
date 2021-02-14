/**
 * @author ooooo
 * @date 2021/2/14 09:43 
 */

#ifndef CPP_0765__SOLUTION2_H_
#define CPP_0765__SOLUTION2_H_

#include <vector>
#include <iostream>

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

		bool connect(int i, int j) {
			int pi = find(i), pj = find(j);
			if (pi == pj) return true;
			p[pi] = pj;
			n--;
			return false;
		}
	};

	int minSwapsCouples(vector<int> &row) {
		int n = row.size();
		UF uf(n / 2);
		for (int i = 0; i < n; i += 2) {
			uf.connect(row[i] / 2, row[i + 1] / 2);
		}
		return n / 2 - uf.n;
	}
};

#endif //CPP_0765__SOLUTION2_H_
