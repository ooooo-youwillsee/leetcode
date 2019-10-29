#include <vector>
#include <iostream>
#include <map>

using namespace std;

/**
 * hash表
 */
class Solution2 {
public:

    static vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;

        map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]] = i;
            if (map.find(target - nums[i]) != map.end()) {
                result.push_back(i);
                result.push_back(map[target - nums[i]]);
            }
        }
        return result;
    }
};