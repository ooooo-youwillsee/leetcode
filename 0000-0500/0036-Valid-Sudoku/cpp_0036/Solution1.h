//
// Created by ooooo on 2019/11/21.
//
#ifndef CPP_0036_SOLUTION1_H
#define CPP_0036_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution1 {

private:

public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int row[9][9] = {0}, col[9][9] = {0}, matrix[9][9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0' - 1;
                row[i][num]++;
                col[j][num]++;
                int bIndex = (i / 3) * 3 + j / 3;
                matrix[bIndex][num]++;
                if (row[i][num] == 2 || col[j][num] == 2 ||
                    matrix[bIndex][num] == 2) {
                    return false;
                }
            }
        }
        return true;
    }

};

#endif //CPP_0036_SOLUTION1_H
