//
// Created by lenovo on 2019/6/12.
//

#ifndef BSTREE_SOLUTION_H
#define BSTREE_SOLUTION_H

#include "BSTree.h"
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    Solution();
    void Input();
    int GetResult();
    void Output();

private:
    vector<int> array;
    int ans;
};


#endif //BSTREE_SOLUTION_H
