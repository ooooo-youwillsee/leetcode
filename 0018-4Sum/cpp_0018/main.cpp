#include <iostream>
#include "Solutoin1.h"

int main() {

    vector<int> nums = {1, 0, -1, 0, -2, 2};

    Solution solution;
    vector<vector<int>> res = solution.fourSum(nums, 0);

    for (int i = 0; i < res.size(); ++i) {
        cout << endl;
        for (int j = 0; j < res[i].size(); ++j) {
            if (j == 0) {
                cout << "[";
            }
            if (j == res[i].size() - 1) {
                cout << res[i][j] << "]";
            } else {
                cout << res[i][j] << ",";
            }

        }
    }
    return 0;
}