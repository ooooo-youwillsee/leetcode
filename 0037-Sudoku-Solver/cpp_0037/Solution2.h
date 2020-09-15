/**
 * @author ooooo
 * @date 2020/9/15 11:13 
 */

#ifndef CPP_0037__SOLUTION2_H_
#define CPP_0037__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution2 {
 public:;
	vector<unordered_set<char>> groups = vector<unordered_set<char>>(9);
	vector<unordered_set<char>> rows = vector<unordered_set<char>>(9);
	vector<unordered_set<char>> cols = vector<unordered_set<char>>(9);

	bool dfs(int i, vector<vector<char>> &board) {
		if (i == 81) return true;
		int row = i / 9, col = i % 9;
		char c = board[row][col];
		if (c != '.') {
			return dfs(i + 1, board);
		}
		for (char k = '1'; k <= '9'; ++k) {
			if (rows[row].count(k) || cols[col].count(k) || groups[row / 3 * 3 + col / 3].count(k)) continue;
			rows[row].insert(k);
			cols[col].insert(k);
			groups[row / 3 * 3 + col / 3].insert(k);
			board[row][col] = k;
			if (dfs(i + 1, board)) return true;
			rows[row].erase(k);
			cols[col].erase(k);
			groups[row / 3 * 3 + col / 3].erase(k);
			board[row][col] = '.';
		}
		return false;
	}

	void solveSudoku(vector<vector<char>> &board) {
		for (int row = 0; row < 9; ++row) {
			for (int col = 0; col < 9; ++col) {
				char c = board[row][col];
				rows[row].insert(c);
				cols[col].insert(c);
				groups[row / 3 * 3 + col / 3].insert(c);
			}
		}
		dfs(0, board);
	}
};

#endif //CPP_0037__SOLUTION2_H_
