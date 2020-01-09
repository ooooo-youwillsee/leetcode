#include <iostream>
#include "Solution1.h"

void test(int num) {
    Solution s;
    cout << s.countPrimes(num) << endl;
}

int main() {
    test(10);
    test(499979);
    return 0;
}