//
// Created by Mac on 2020/3/6.
//

#include "File1.h"



using namespace std;
/**
 * problem 3
 *
 * 输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
 * @param head
 * @return
 */
std::vector<int> printListFromTailToHead(JZListNode* head){

    vector<int> temp;
    vector<int> res;

    JZListNode *p = head;
    while(p != NULL){
        temp.push_back(p->val);
        p = p->next;
    }

    for(auto it = temp.end(); it != temp.begin();){
        res.push_back(*(--it));
    }

    return res;
}
