#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

int main() {
    vector<vector<int>> vec = {
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}
    };
    Solution s;
    cout << s.minimumTotal(vec) << endl;
    return 0;
}