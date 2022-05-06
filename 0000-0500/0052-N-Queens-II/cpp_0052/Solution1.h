//
// Created by ooooo on 2019/12/7.
//
#ifndef CPP_0052_SOLUTION1_H
#define CPP_0052_SOLUTION1_H

class Solution {

private:
    int total = 0;
    int n;

    void dfs(int row, int col, int pie, int na) {
        if (row >= n) {
            total += 1;
            return;
        }

        int bits = ~(col | pie | na) & ((1 << n) - 1);
        while (bits) {
            int bit = bits & -bits;
            dfs(row + 1, (col | bit), (pie | bit) << 1, (na | bit) >> 1);
            bits = bits & (bits - 1);
        }
    }

public:
    int totalNQueens(int n) {
        total = 0;
        this->n = n;
        dfs(0, 0, 0, 0);
        return total;
    }
};

#endif //CPP_0052_SOLUTION1_H
