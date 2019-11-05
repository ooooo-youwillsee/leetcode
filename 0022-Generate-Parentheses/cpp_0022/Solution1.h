//
// Created by ooooo on 2019/11/5.
//
#ifndef CPP_0022_SOLUTION1_H
#define CPP_0022_SOLUTION1_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {

private:

    void gen(vector<string> &vec, int left, int right, int n, string result) {
        if (left == n && right == n) {
            vec.push_back(result);
        }
        if (left < n) gen(vec, left + 1, right, n, result + "(");
        if (right < left) gen(vec, left, right + 1, n, result + ")");
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n <= 0) return res;
        gen(res, 0, 0, n, "");
        return res;
    }
};

#endif //CPP_0022_SOLUTION1_H
