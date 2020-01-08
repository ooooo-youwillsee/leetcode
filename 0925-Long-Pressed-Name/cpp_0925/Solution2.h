//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0925_SOLUTION2_H
#define CPP_0925_SOLUTION2_H

#include <iostream>
#include <vector>


using namespace std;

/**
 * 分组
 */
class Solution {

private:

    struct Group {
        char c;
        int count;

        Group(char c) {
            this->c = c;
            this->count = 1;
        }

        bool operator<(const Group &other) {
            return this->count < other.count;
        }
    };

public:

    vector<Group> group(string s) {
        vector<Group> res;
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                res.push_back(Group(s[i]));
            } else {
                res[res.size() - 1].count += 1;
            }
        }
        return res;
    }

    bool isLongPressedName(string name, string typed) {
        if (name.empty()) return typed.empty();
        if (typed.size() < name.size()) return false;
        vector<Group> nameGroup = group(name);
        vector<Group> typedGroup = group(typed);
        if (nameGroup.size() == typedGroup.size()) {
            for (int i = 0; i < nameGroup.size(); ++i) {
                if (typedGroup[i] < nameGroup[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};

#endif //CPP_0925_SOLUTION2_H
