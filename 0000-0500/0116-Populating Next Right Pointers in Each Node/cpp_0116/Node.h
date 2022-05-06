/**
 * @author ooooo
 * @date 2020/10/15 19:34 
 */

#ifndef CPP_0116__NODE_H_
#define CPP_0116__NODE_H_

#include <iostream>
#include <vector>

using namespace std;

class Node {
 public:
	int val;
	Node *left;
	Node *right;
	Node *next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node *_left, Node *_right, Node *_next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

#endif //CPP_0116__NODE_H_
