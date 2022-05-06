//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0345_SOLUTION1_H
#define CPP_0345_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    bool isVowel(char c) {
        for (int i = 0; i < vowels.size(); ++i) {
            if (vowels[i] == tolower(c)) return true;
        }
        return false;
    }

    string reverseVowels(string s) {
        if (s.size() <= 1) return s;
        for (int i = 0, j = s.size() - 1; i < j;) {
            while (i <= s.size() - 1 && !isVowel(s[i])) i++;
            while (j >= 0 && !isVowel(s[j])) j--;
            if (i > j) break;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};

#endif //CPP_0345_SOLUTION1_H
