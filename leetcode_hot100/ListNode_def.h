// 定义链表
#ifndef _LISTNODE_DEF_H_
#define _LISTNODE_DEF_H_
#include<iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x):val(x), next(nullptr) {} // 节点构造函数
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

#endif
