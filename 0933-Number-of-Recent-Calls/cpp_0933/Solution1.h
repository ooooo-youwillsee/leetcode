//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0933_SOLUTION1_H
#define CPP_0933_SOLUTION1_H

#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {

private:
    queue<int> q;

public:
    RecentCounter() {

    }

    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};


#endif //CPP_0933_SOLUTION1_H
