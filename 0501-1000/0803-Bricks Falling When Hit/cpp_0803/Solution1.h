/**
 * @author ooooo
 * @date 2021/1/16 18:28 
 */

#ifndef CPP_0803__SOLUTION1_H_
#define CPP_0803__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	int m, n;
	vector<int> p, pSize;
	vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

	vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
		m = grid.size(), n = grid[0].size();

		vector<vector<int>> copy = grid;
		for (int i = 0; i < hits.size(); ++i) {
			int x = hits[i][0], y = hits[i][1];
			// 初始化状态
			copy[x][y] = 0;
		}

		// 初始化并查集, 屋顶为 size
		int size = m * n;
		p.assign(size + 1, 0);
		pSize.assign(size + 1, 1);
		for (int i = 0; i < p.size(); ++i) {
			p[i] = i;
		}

		// 处理第0行屋顶
		for (int j = 0; j < n; ++j) {
			if (copy[0][j] == 1) {
				connect(tranIndex(0, j), size);
			}
		}

		// 从第二行到尾行
		for (int i = 1; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (copy[i][j] == 1) {
					if (i - 1 >= 0 && copy[i - 1][j] == 1) {
						connect(tranIndex(i - 1, j), tranIndex(i, j));
					}
					if (j - 1 >= 0 && copy[i][j - 1] == 1) {
						connect(tranIndex(i, j - 1), tranIndex(i, j));
					}
				}
			}
		}

		vector<int> ans(hits.size());
		// 补砖块
		for (int i = hits.size() - 1; i >= 0; --i) {
			int x = hits[i][0], y = hits[i][1];

			// 原先就是为0，所以没有任何砖块掉落
			if (grid[x][y] == 0) {
				continue;
			}
			int prevSize = pSize[find(size)];

			// 如果敲碎是屋顶的砖块
			if (x == 0) {
				connect(tranIndex(x, y), size);
			}
			// 连接
			for (auto &direction: directions) {
				int nx = x + direction[0];
				int ny = y + direction[1];
				if (inArea(nx, ny) && copy[nx][ny] == 1) {
					connect(tranIndex(x, y), tranIndex(nx, ny));
				}
			}
			int curSize = pSize[find(size)];
			ans[i] = max(0, curSize - prevSize - 1);

			// 最后添加这个砖块
			copy[x][y] = 1;
		}

		return ans;
	}

	bool inArea(int i, int j) {
		return i >= 0 && i < m && j >= 0 && j < n;
	}

	int tranIndex(int i, int j) {
		return n * i + j;
	}

	int find(int i) {
		if (p[i] == i) return i;
		return p[i] = find(p[i]);
	}

	bool connect(int i, int j) {
		int pi = find(i), pj = find(j);
		if (pi == pj) return true;
		p[pi] = pj;
		pSize[pj] += pSize[pi];
		return false;
	}
};

#endif //CPP_0803__SOLUTION1_H_
