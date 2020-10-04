/**
 * @author ooooo
 * @date 2020/10/4 12:42 
 */

#ifndef CPP_0002__LISTNODE_H_
#define CPP_0002__LISTNODE_H_

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#endif //CPP_0002__LISTNODE_H_
