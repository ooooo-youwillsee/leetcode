//
// Created by ooooo on 2020/1/9.
//
#ifndef CPP_0290_SOLUTION1_H
#define CPP_0290_SOLUTION1_H

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:

    vector<string> split(string s, string sep) {
        s += sep;
        int i = s.find(sep);
        vector<string> res;
        int j = 0;
        while (i != -1) {
            res.push_back(s.substr(j, i - j));
            j = i + 1;
            i = s.find(sep, i + 1);
        }
        return res;
    }


    bool wordPattern(string pattern, string str) {
        vector<string> strs = split(str, " ");
        if (strs.size() != pattern.size()) return false;
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        for (int i = 0; i < pattern.size(); ++i) {
            if (m1.count(pattern[i]) && m1[pattern[i]] != strs[i]) return false;
            else {
                if (m2.count(strs[i]) && m2[strs[i]] != pattern[i]) return false;
                m1[pattern[i]] = strs[i];
                m2[strs[i]] = pattern[i];
            }
        }

        return true;
    }

};

#endif //CPP_0290_SOLUTION1_H
