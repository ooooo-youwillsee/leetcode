//
// Created by ooooo on 2020/1/9.
//
#ifndef CPP_0205_SOLUTION1_H
#define CPP_0205_SOLUTION1_H

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        for (int i = 0; i < s.size(); ++i) {
            if (m1.count(s[i])) {
                if (m1[s[i]] != t[i]) return false;
            } else {
                if (m2.count(t[i]) && m2[t[i]] != s[i]) return false;
                // 相互映射
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
        }

        return true;
    }
};


#endif //CPP_0205_SOLUTION1_H
