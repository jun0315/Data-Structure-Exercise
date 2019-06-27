//
// Created by lenovo on 2019/6/14.
//

#ifndef PROBLEM1_SOLUTION_H
#define PROBLEM1_SOLUTION_H
#include <iostream>
#include "Sort.h"
#include <string>
using namespace std;
class Solution {
public:
    Solution();
    virtual ~Solution();

protected:
private:
    void Input();
    bool CheckArgument();
    void Output();
    Sort s;
    Sort t;

};


#endif //PROBLEM1_SOLUTION_H
