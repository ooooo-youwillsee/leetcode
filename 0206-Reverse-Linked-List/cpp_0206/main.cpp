#include <iostream>
#include <ctime>
#include "Solution1.h"
#include "Solution2.h"

using namespace std;

int main() {

    srand(time(NULL));
    ListNode *node = new ListNode(1);
    ListNode *head = node;
    ListNode *xx = node;
    for (int i = 0; i < 10; ++i) {
        head->next = new ListNode(rand() % 10);
        head = head->next;
    }

    while (node) {
        cout << node->val << " ";
        node = node->next;
    }

    cout << endl;

    //Solution1 solution1;
    //ListNode *result1 = solution1.reverseList(xx);
    //while (result1) {
    //    cout << result1->val << " ";
    //    result1 = result1->next;
    //}


    cout << endl;

    Solution2 solution2;
    ListNode *result2 = solution2.reverseList(xx);
    while (result2) {
        cout << result2->val << " ";
        result2 = result2->next;
    }
    return 0;
}