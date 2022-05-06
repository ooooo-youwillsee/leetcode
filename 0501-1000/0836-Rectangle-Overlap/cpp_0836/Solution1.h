/**
 * @author ooooo
 * @date 2020/9/30 10:19 
 */

#ifndef CPP_0836__SOLUTION1_H_
#define CPP_0836__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
		return !(
			rec1[2] <= rec2[0] ||   // left
			rec1[3] <= rec2[1] ||   // bottom
			rec1[0] >= rec2[2] ||   // right
			rec1[1] >= rec2[3]);    // top
	}
};

#endif //CPP_0836__SOLUTION1_H_
