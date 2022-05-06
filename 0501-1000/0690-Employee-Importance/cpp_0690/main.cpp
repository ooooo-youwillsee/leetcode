#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<Employee *> vec, int id) {
  Solution solution;
  cout << solution.getImportance(vec, id) << endl;
}

int main() {
  test({
           new Employee(1, 5, {2, 3}),
           new Employee(2, 3, {}),
           new Employee(3, 3, {})}, 1);
  return 0;
}
