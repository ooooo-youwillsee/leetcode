//
// Created by ooooo on 2020/1/13.
//
#ifndef CPP_0690__EMPLOYEE_H_
#define CPP_0690__EMPLOYEE_H_

#include <iostream>
#include <vector>

using namespace std;

class Employee {
 public:
  // It's the unique ID of each node.
  // unique id of this employee
  int id;
  // the importance value of this employee
  int importance;
  // the id of direct subordinates
  vector<int> subordinates;

  Employee(int id, int importance, const vector<int> &subordinates)
      : id(id), importance(importance), subordinates(subordinates) {}

  Employee() {}
};

#endif //CPP_0690__EMPLOYEE_H_
