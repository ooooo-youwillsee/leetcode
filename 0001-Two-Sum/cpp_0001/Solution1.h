#include <vector>
#include <iostream>

using namespace std;

/**
 * 暴力破解法
 */
class Solution1 {
public:

    static vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 1; j < nums.size(); ++j) {
                if (nums[j] + nums[i] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};