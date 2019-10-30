#include <iostream>
#include "Solution2.h"


int main() {

    MyStack stack1;

    stack1.push(2);
    stack1.push(1);
    cout << stack1.top() << " " << stack1.pop();
    return 0;
}