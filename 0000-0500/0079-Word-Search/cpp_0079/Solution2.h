/**
 * @author ooooo
 * @date 2020/9/13 09:34 
 */

#ifndef CPP_0079__SOLUTION2_H_
#define CPP_0079__SOLUTION2_H_

#include <vector>
#include <iostream>

using namespace std;

class Solution2 {
 public:

	vector<vector<char>> board;
	vector<vector<bool>> visited;
	vector<vector<int>> dx_dy = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	int m = 0, n = 0;

	bool inArea(int i, int j) {
		return i < m && i >= 0 && j < n && j >= 0;
	}

	bool dfs(int i, int j, string &word, int k) {
		visited[i][j] = true;
		if (board[i][j] != word[k]) return visited[i][j] = false;
		if (k == word.size() - 1) return true;
		for (int p = 0; p < dx_dy.size(); ++p) {
			int ni = i + dx_dy[p][0];
			int nj = j + dx_dy[p][1];
			if (!inArea(ni, nj) || visited[ni][nj]) continue;
			if (dfs(ni, nj, word, k + 1)) return true;
		}
		return visited[i][j] = false;
	}

	bool exist(vector<vector<char>> &board, string word) {
		this->board = board;
		this->m = board.size();
		this->n = board[0].size();
		this->visited = vector<vector<bool>>(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dfs(i, j, word, 0)) return true;
			}
		}
		return false;
	}
};

#endif //CPP_0079__SOLUTION2_H_
