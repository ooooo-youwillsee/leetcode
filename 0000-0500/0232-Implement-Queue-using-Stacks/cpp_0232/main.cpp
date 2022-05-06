#include <iostream>
#include "Solution1.h"

int main() {

    MyQueue q;
    q.push(2);
    q.push(1);
    cout << q.peek() << " " << q.pop();

    return 0;
}