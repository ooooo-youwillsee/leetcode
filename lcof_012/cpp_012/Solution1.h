//
// Created by ooooo on 2020/3/10.
//
#ifndef CPP_012__SOLUTION1_H_
#define CPP_012__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * dfs( rows * cols * len(word))
 */
class Solution {
 public:

  bool is_valid(int i, int j, int word_index) {
    return i >= 0 && i < board.size() && j >= 0 && j < board[0].size()
        && board[i][j] == word[word_index] && !marked[i][j];
  }

  bool dfs(int i, int j, int word_index) {
    if (word_index == word.size()) return true;
    if (!is_valid(i, j, word_index)) return false;
    marked[i][j] = true;
    for (int k = 0; k < 4; ++k) {
      int dx = i + dx_dy[k][0], dy = j + dx_dy[k][1];
      if (dfs(dx, dy, word_index + 1)) {
        return true;
      }
    }
    marked[i][j] = false;
    return false;
  }

  vector<vector<char>> board;
  vector<vector<bool>> marked;
  vector<vector<int>> dx_dy = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  string word;

  bool exist(vector<vector<char>> &board, string word) {
    int rows = board.size(), cols = board[0].size();
    this->board = board;
    this->word = word;
    this->marked.assign(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (dfs(i, j, 0)) return true;
      }
    }
    return false;
  }
};

#endif //CPP_012__SOLUTION1_H_
