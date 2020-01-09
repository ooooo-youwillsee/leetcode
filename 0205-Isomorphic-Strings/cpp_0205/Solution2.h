//
// Created by ooooo on 2020/1/9.
//
#ifndef CPP_0205_SOLUTION2_H
#define CPP_0205_SOLUTION2_H


#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:

    bool help(string s, string t) {
        unordered_map<char, char> m;
        for (int i = 0; i < s.size(); ++i) {
            if (m.count(s[i])) {
                if (m[s[i]] != t[i]) return false;
            } else {
                m[s[i]] = t[i];
            }
        }
        return true;
    }

    bool isIsomorphic(string s, string t) {
        return help(s, t) && help(t, s);
    }
};

#endif //CPP_0205_SOLUTION2_H
