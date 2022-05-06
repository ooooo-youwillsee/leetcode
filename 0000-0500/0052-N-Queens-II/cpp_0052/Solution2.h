//
// Created by ooooo on 2019/11/14.
//
#ifndef CPP_0052_SOLUTION2_H
#define CPP_0052_SOLUTION2_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:

    void help(int n, int row, int &res, vector<bool> &cols,
              vector<bool> &pies, vector<bool> &nas) {
        if (row >= n) {
            res += 1;
            return;
        }

        for (int col = 0; col < n; ++col) {
            int ll = col + row;
            int rr = row - col + n - 1;
            if (cols[col] && pies[ll] && nas[rr]) {
                cols[col] = false;
                pies[ll] = false;
                nas[rr] = false;

                help(n, row + 1, res, cols, pies, nas);

                cols[col] = true;
                pies[ll] = true;
                nas[rr] = true;
            }
        }
    }

public:
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> cols(n, true);
        vector<bool> pies(2 * n - 1, true);
        vector<bool> nas(2 * n - 1, true);
        help(n, 0, res, cols, pies, nas);
        return res;
    }
};

#endif //CPP_0052_SOLUTION2_H
