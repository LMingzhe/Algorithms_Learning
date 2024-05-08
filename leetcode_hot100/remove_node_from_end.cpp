#include <iostream>
#include "ListNode_def.h"

/// leetcode 19 删除链表的倒数第N个节点
/// @brief 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
/// 时间复杂度O(n) 空间复杂度O(1)

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (head->next == nullptr) return nullptr; // 处理只有一个节点的情况
        ListNode* dummyHead = new ListNode(0); // 为统一节点删除操作，创建一个虚拟头节点
        dummyHead->next = head; 
        // 使用双指针中的快慢指针解决 
        ListNode* pre = dummyHead;
        ListNode* cur = dummyHead;
        for (int i = 1; i <= n + 1; i++) // cur先走走n+1步
        {
            cur = cur -> next;
        }
        while (cur != nullptr) // 当cur末尾指向空指针时，pre指向待删除节点的前一个节点
        {
            pre = pre->next;
            cur = cur->next;
        }
        ListNode* tmp = pre->next;
        pre->next = tmp->next;
        delete tmp;
        tmp = nullptr;
        return dummyHead->next;
    }
};