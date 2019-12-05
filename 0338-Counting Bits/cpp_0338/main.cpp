#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

int main() {

    Solution s;
    vector<int> res = s.countBits(5);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}