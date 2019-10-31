//
// Created by ooooo on 2019/10/29.
//

#include <vector>
#include <iostream>
#include "Solution1.h"
#include "Solution2.h"

using namespace std;

int main() {


    vector<int> data = {2, 7, 11, 15};

    Solution1 solution1;
    vector<int> result1 = solution1.twoSum(data, 9);
    for (int i = 0; i < result1.size(); ++i) {
        cout << result1[i] << " ";
    }
    cout << endl;


    Solution2 solution2;
    vector<int> result2 = solution2.twoSum(data, 9);
    for (int i = 0; i < result2.size(); ++i) {
        cout << result2[i] << " ";
    }
    cout << endl;

}
