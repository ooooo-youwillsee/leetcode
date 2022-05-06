//
// Created by ooooo on 2019/11/1.
//
#ifndef CPP_0242_SOLUTION2_H
#define CPP_0242_SOLUTION2_H

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m1;
        map<char, int> m2;

        for (auto i : s) {
            map<char, int>::iterator it = m1.find(i);
            if (it == m1.end()) {
                m1[i] = 1;
            } else {
                m1[i] = it->second + 1;
            }
        }

        for (auto i : t) {
            map<char, int>::iterator it = m2.find(i);
            if (it == m1.end()) {
                m2[i] = 1;
            } else {
                m2[i] = it->second + 1;
            }
        }

        return m1 == m2;
    }
};

#endif //CPP_0242_SOLUTION2_H
