#include <iostream>
#include "ListNode_def.h"

/// leetcode 142 较难，过程需要理解
/// @brief 环形链表 给定一个链表的头节点head，返回链表开始入环的第一个节点。如果链表无环，则返回null
/// 时间复杂度O(n) 空间复杂度O(1)

class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return nullptr;
    }
};