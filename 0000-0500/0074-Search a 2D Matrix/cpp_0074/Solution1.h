/**
 * @author ooooo
 * @date 2021/3/30 16:09 
 */

#ifndef CPP_0074__SOLUTION1_H_
#define CPP_0074__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(), n = matrix[0].size();
		int i = 0, j = n-1;
		while (i >= 0 && i < m && j >=0 && j < n) {
			if (matrix[i][j] < target) {
				i++;
			}else if (matrix[i][j] > target) {
				j--;
			}else {
				return true;
			}
		}
		return false;
	}
};

#endif //CPP_0074__SOLUTION1_H_
