/**
 * @author ooooo
 * @date 2021/3/19 19:25 
 */

#ifndef CPP_1603__SOLUTION1_H_
#define CPP_1603__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class ParkingSystem {
 public:
	int big;
	int medium;
	int small;
	ParkingSystem(int big, int medium, int small) {
		this->big= big;
		this->medium = medium;
		this->small = small;
	}

	bool addCar(int carType) {
		if (carType == 1) {
			if (big == 0) return false;
			big--;
		}else if (carType == 2) {
			if (medium == 0) return false;
			medium--;
		}else {
			if (small == 0) return false;
			small--;
		}
		return true;
	}
};

#endif //CPP_1603__SOLUTION1_H_
