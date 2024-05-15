#include <iostream>
#include "ListNode_def.h"

/// leetcode 21 合并两个有序链表
/// @brief 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
// 时间复杂度O(min(n, m)) n, m 为两个链表长度 空间复杂度O(1)

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* dummyNode = new ListNode(0);
        ListNode* cur = dummyNode;
        ListNode* curList1 = list1;
        ListNode* curList2 = list2;
        while (curList1 != nullptr && curList2 != nullptr)
        {
            if (curList1->val <= curList2->val)
            {
                cur->next = curList1;
                cur = curList1;
                curList1 = curList1->next;
            }
            else
            {
                cur->next = curList2;
                cur =  curList2;
                curList2 = curList2->next;
            }
        }
        // 其中一个链表已遍历完成，剩下的另一个链表直接连接到末尾
        if (curList1 != nullptr) cur->next = curList1;
        if (curList2 != nullptr) cur->next = curList2;
        return dummyNode->next;
    }
};