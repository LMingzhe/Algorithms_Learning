#include<iostream>
#include<vector>
#include "ListNode_def.h"

using namespace std;

/// leetcode 203
/// @brief 删除链表指定元素节点 时间复杂度O(n),主要是消耗在寻找元素上，删除操作只需O(1) 空间复杂度O(1)

// 设置虚拟头节点
class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        // 设置一个虚拟头节点
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* cur = dummyHead;
        while (cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};