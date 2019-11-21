//
// Created by ooooo on 2019/11/21.
//
#ifndef CPP_0037_SOLUTION1_H
#define CPP_0037_SOLUTION1_H

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {

private:

    bool check(vector<vector<char>> &board, int i, int j, char k) {
        for (int row = 0; row < 9; ++row) if (board[row][j] == k) return false;
        for (int col = 0; col < 9; ++col) if (board[i][col] == k) return false;
        int x = i / 3 * 3, y = j / 3 * 3;
        for (int row = x; row < x + 3; ++row)
            for (int col = y; col < y + 3; ++col) if (board[row][col] == k) return false;
        return true;
    }


    bool resolve(vector<vector<char>> &board, int n) {
        if (n >= 81) return true;
        int row = n / 9, col = n % 9;
        if (board[row][col] != '.') return resolve(board, n + 1);
        for (char k = '1'; k <= '9'; k++) {
            if (check(board, row, col, k)) {
                char c = board[row][col];
                board[row][col] = k;
                if (resolve(board, n + 1)) return true;
                board[row][col] = c;
            }
        }
        return false;
    }

public:

    void solveSudoku(vector<vector<char>> &board) {
        resolve(board, 0);
    }
};

#endif //CPP_0037_SOLUTION1_H
