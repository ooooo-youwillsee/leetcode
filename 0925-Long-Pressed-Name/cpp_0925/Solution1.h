//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0925_SOLUTION1_H
#define CPP_0925_SOLUTION1_H

#include <iostream>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name.empty()) return typed.empty();
        if (typed.size() < name.size()) return false;
        int i = 0, j = 0;
        if (name[i++] != typed[j++]) return false;
        while (i < name.size() && j < typed.size()) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            } else {
                if (typed[j] == typed[j - 1]) {
                    j++;
                    continue;
                }
                return false;
            }
        }
        // name没有遍历完
        if (i != name.size()) return false;
        // typed没有遍历完，检查后面元素是否一致
        if (j != typed.size()) {
            for (int k = j; k < typed.size(); ++k) {
                if (typed[k] != typed[k - 1]) return false;
            }
        }
        return true;
    }
};

#endif //CPP_0925_SOLUTION1_H
