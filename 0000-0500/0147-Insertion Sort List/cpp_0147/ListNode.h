/**
 * @author ooooo
 * @date 2020/11/20 09:10 
 */

#ifndef CPP_0147__LISTNODE_H_
#define CPP_0147__LISTNODE_H_

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#endif //CPP_0147__LISTNODE_H_
