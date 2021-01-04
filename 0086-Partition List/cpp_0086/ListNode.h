/**
 * @author ooooo
 * @date 2021/1/4 16:15 
 */

#ifndef CPP_0086__LISTNODE_H_
#define CPP_0086__LISTNODE_H_

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#endif //CPP_0086__LISTNODE_H_
