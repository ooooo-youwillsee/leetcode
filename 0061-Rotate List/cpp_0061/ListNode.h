/**
 * @author ooooo
 * @date 2020/10/5 18:03 
 */

#ifndef CPP_0061__LISTNODE_H_
#define CPP_0061__LISTNODE_H_

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#endif //CPP_0061__LISTNODE_H_
