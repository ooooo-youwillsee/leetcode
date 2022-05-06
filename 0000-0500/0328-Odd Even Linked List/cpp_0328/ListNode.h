/**
 * @author ooooo
 * @date 2020/11/13 21:07 
 */

#ifndef CPP_0328__LISTNODE_H_
#define CPP_0328__LISTNODE_H_

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //CPP_0328__LISTNODE_H_
