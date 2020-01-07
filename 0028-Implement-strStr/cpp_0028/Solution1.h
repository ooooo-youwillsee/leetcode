//
// Created by ooooo on 2020/1/7.
//
#ifndef CPP_0028_SOLUTION1_H
#define CPP_0028_SOLUTION1_H

#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (haystack == "" || haystack.size() < needle.size()) return -1;
        int k = 0, count = 0;
        for (; k <= haystack.size() - needle.size(); ++k) {
            count = 0;
            for (int i = 0; i < needle.size(); ++i) {
                if (haystack[k + i] != needle[i]) {
                    break;
                }
                count++;
            }
            if (count == needle.size()) return k;
        }
        return -1;
    }
};

#endif //CPP_0028_SOLUTION1_H
