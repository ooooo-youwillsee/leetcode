/**
 * @author ooooo
 * @date 2021/1/25 19:35 
 */

#ifndef CPP_0959__SOLUTION1_H_
#define CPP_0959__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <queue>

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

		bool connect(int i, int j) {
			int pi = find(i), pj = find(j);
			if (pi == pj) return true;
			p[pi] = pj;
			n--;
			return false;
		}
	};

	/**
	 *   0
	 * 3   1
	 *   2
	 * @param grid
	 * @return
	 */
	int regionsBySlashes(vector<string> &grid) {
		int n = grid.size();
		UF uf(4 * n * n);
		// 左上合并
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int index = 4 * (j + i * n);
				if (grid[i][j] == '/') {
					uf.connect(index + 1, index + 2);
					uf.connect(index + 0, index + 3);
				} else if (grid[i][j] == '\\') {
					uf.connect(index + 0, index + 1);
					uf.connect(index + 3, index + 2);
				} else {
					uf.connect(index + 0, index + 1);
					uf.connect(index + 0, index + 2);
					uf.connect(index + 0, index + 3);
				}

				// 向上一层合并
				if (i >= 1) {
					uf.connect(index + 0, 4 * ((i - 1) * n + j) + 2);
				}
				if (j >= 1) {
					uf.connect(index + 3, 4 * (i * n + j - 1) + 1);
				}
			}
		}

		return uf.n;
	}

};

#endif //CPP_0959__SOLUTION1_H_
