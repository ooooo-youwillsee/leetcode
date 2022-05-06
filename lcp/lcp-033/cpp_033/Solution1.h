/**
 * @author ooooo
 * @date 2021/4/10 21:05 
 */

#ifndef CPP_033__SOLUTION1_H_
#define CPP_033__SOLUTION1_H_

class Solution {
 public:
	int storeWater(vector<int> &bucket, vector<int> &vat) {
		int n = bucket.size();
		int a = 1;
		int b = 0;
		for (int i = 0; i < n; i++) {
			if (bucket[i] == 0) {
				b = max(b, vat[i]);
			} else {
				b = max(b, (int) ceil(1.0 * vat[i] / bucket[i]));
			}
		}
		int ans = INT_MAX;
		// 遍历倾倒次数
		while (a <= b) {
			int cur = a;
			for (int i = 0; i < n; i++) {
				if (vat[i] == 0) continue;
				cur += max(0, (int) ceil(1.0 * vat[i] / a) - bucket[i]);
			}
			ans = min(ans, cur);
			a++;
		}
		return ans == INT_MAX ? 0 : ans;
	}
};

#endif //CPP_033__SOLUTION1_H_
