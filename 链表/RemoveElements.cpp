#include<iostream>
#include<vector>
#include "ListNode_def.h"

using namespace std;

/// leetcode 203
/// @brief 删除链表指定元素节点 时间复杂度O(n),主要是消耗在寻找元素上，删除操作只需O(1) 空间复杂度O(1)

// 没有设置虚拟头节点
class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        // 删除头节点
        while (head != NULL && head->val == val)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        // 删除非头节点
        ListNode* cur = head;
        while (cur != NULL && cur->next != NULL)
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

        return head;
    }
};