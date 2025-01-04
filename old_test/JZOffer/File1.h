//
// Created by Mac on 2020/3/6.
//

#ifndef LEETCODEDEMO_FILE1_H
#define LEETCODEDEMO_FILE1_H

#include <iostream>
#include <vector>

struct JZListNode {
        int val;
        struct JZListNode *next;
    JZListNode(int x) :
             val(x), next(NULL) {
       }
};

std::vector<int> printListFromTailToHead(JZListNode* head);
#endif //LEETCODEDEMO_FILE1_H
