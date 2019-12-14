//
// Created by ooooo on 2019/12/14.
//
#ifndef CPP_0804_SOLUTION1_H
#define CPP_0804_SOLUTION1_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {

        string arr[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                        "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        unordered_set<string> set;
        for (const auto &word : words) {
            string s;
            for (const auto &c : word) {
                s += arr[c - 'a'];
            }
            set.insert(s);
        }
        return set.size();
    }
};

#endif //CPP_0804_SOLUTION1_H
