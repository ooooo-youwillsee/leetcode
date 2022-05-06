/**
 * @author ooooo
 * @date 2020/9/25 22:36 
 */

#ifndef CPP_0023__LISTNODE_H_
#define CPP_0023__LISTNODE_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //CPP_0023__LISTNODE_H_
