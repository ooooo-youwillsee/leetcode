#include <iostream>
#include <string>
#include "Solution1.h"

int main() {

    string s = "[]{}{";

    Solution1 solution1;
    cout << solution1.isValid(s);

    return 0;
}