#include <iostream>
#include "Solution1.h"

void test(vector<string> list1, vector<string> list2) {
  Solution solution;
  for (const auto &item: solution.findRestaurant(list1, list2)) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  test({"Shogun", "Tapioca Express", "Burger King", "KFC"},
       {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"});
  test({"Shogun", "Tapioca Express", "Burger King", "KFC"},
       {"KFC", "Shogun", "Burger King"});
  return 0;
}
