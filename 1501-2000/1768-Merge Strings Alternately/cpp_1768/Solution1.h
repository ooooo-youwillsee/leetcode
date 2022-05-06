/**
 * @author ooooo
 * @date 2021/2/28 13:16 
 */

#ifndef INC_1768_MERGE_STRINGS_ALTERNATELY__SOLUTION1_H_
#define INC_1768_MERGE_STRINGS_ALTERNATELY__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
	string mergeAlternately(string word1, string word2) {
		string ans = "";
		int i = 0, j = 0;
		while (i < word1.size() && j < word2.size()) {
			ans += word1[i++];
			ans += word2[j++];
		}
		while (i < word1.size()) {
			ans += word1[i++];
		}
		while (j < word2.size()) {
			ans += word2[j++];
		}

		return ans;
	}

};

#endif //INC_1768_MERGE_STRINGS_ALTERNATELY__SOLUTION1_H_
