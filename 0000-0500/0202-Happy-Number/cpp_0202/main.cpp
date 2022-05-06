#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(int num) {
    Solution s;
    cout << s.isHappy(num) << endl;
}

int main() {
    //test(1);
    test(19);
    test(20);
    return 0;
}