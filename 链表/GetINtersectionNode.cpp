#include <iostream>
#include "ListNode_def.h"

/// leetcode 面试题02.07
/// @brief 给你两个单链表的头节点headA和headB，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回NULL
/// 时间复杂度O(n+m)，空间复杂度O(1)

class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        int lenA = 0, lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;

        while (curA->next != nullptr) // 求链表A长度
        {
            lenA++;
            curA = curA->next;
        }
        while (curB->next != nullptr) // 秋链表B长度
        {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // 让curA为最长链表的头，lenA为其长度
        if (lenB > lenA)
        {
            std::swap(lenB, lenA);
            std::swap(curB, curA);
        }

        // 求长度差
        int gap = lenA - lenB;
        // 让curA和curB在同一起点上（末尾位置对齐）
        while (gap--)
        {
            curA = curA->next;
        }
        // 遍历curA和curB，遇到相同则直接返回
        while (curA->next != nullptr)
        {
            if (curA->val == curB->val)
            {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }
};