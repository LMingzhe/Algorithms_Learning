#include <iostream>
#include "ListNode_def.h"

using namespace std;

/// leetcode 24
/// @brief 两两交换链表中的节点

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;

        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            // 记录临时节点
            ListNode* temp = cur->next;
            ListNode* temp1 = cur->next->next->next;

            // 0->1->2->3->4 设当前cur=0
            // 步骤1：0->2
            // 步骤2：2->1
            // 步骤3：1->3->4
            cur->next = cur->next->next;
            cur->next->next = temp;
            cur->next->next->next = temp1;

            cur = cur->next->next; // cur移动两位，准备下一轮交换
        }
        return dummyHead->next;
    }    
};