// 定义链表
#ifndef _LISTNODE_DEF_H_
#define _LISTNODE_DEF_H_
#include<iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr) {} // 节点构造函数
};

#endif
