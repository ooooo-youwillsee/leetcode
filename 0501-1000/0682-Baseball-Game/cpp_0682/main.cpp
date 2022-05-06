#include <iostream>
#include "Solution1.h"

void test(vector<string> vec) {
    Solution s;
    cout << s.calPoints(vec) << endl;
}

int main() {
    test({"5", "2", "C", "D", "+"});
    test({"5", "-2", "4", "C", "D", "9", "+", "+"});
    return 0;
}