//
// Created by ooooo on 2019/11/1.
//
#ifndef CPP_0242_SOLUTION1_H
#define CPP_0242_SOLUTION1_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

#endif //CPP_0242_SOLUTION1_H
