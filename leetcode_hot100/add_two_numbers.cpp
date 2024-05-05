#include <iostream>
#include "ListNode_def.h"

/// leetcode 2 两数相加
/// @brief 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
///        请你将两个数相加，并以相同形式返回一个表示和的链表。
///        你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
/// 时间复杂度O(max(m,n)) m为l1链表长度，n为l2链表长度
/// 空间复杂度O(1) 最终得到的链表不算在辅助空间内

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* curL1 = l1;               // 指向l1链表中当前节点
        ListNode* curL2 = l2;               // 指向l2链表中当前节点
        ListNode* sumHead = new ListNode(); // 头节点为空节点
        ListNode* sumTail = sumHead;        // 指向结果链表的尾节点
        int surplus = 0;                    // 进位
        // l1和l2对应节点都不为空
        while (curL1 && curL2)
        {
            int nodeSum = curL1->val + curL2->val + surplus;
            surplus = 0; // 每次使用完surplus记得重置为0
            if (nodeSum >= 10) // 需要进位
            {
                nodeSum -= 10;
                surplus = 1;
                ListNode* node = new ListNode(nodeSum);
                sumTail->next = node;
                sumTail = node;
            }
            else // 无需进位
            {
                ListNode* node = new ListNode(nodeSum);
                sumTail->next = node;
                sumTail = node;
            }
            curL1 = curL1->next;
            curL2 = curL2->next;
        }
        
        // l2链表已结束，l1剩下的节点直接链接到末尾
        while (curL1)
        {
            int nodeSum = curL1->val + surplus;
            surplus = 0;
            if (nodeSum >= 10)
            {
                nodeSum -= 10;
                surplus = 1;
            }
            ListNode* node = new ListNode(nodeSum);
            sumTail->next = node;
            sumTail = node;
            curL1 = curL1->next;
        }

        // l1链表已结束，l2剩下的节点直接链接到末尾
        while (curL2)
        {
            int nodeSum = curL2->val + surplus;
            surplus = 0;
            if (nodeSum >= 10)
            {
                nodeSum -= 10;
                surplus = 1;
            }
            ListNode* node = new ListNode(nodeSum);
            sumTail->next = node;
            sumTail = node;
            curL2 = curL2->next;
        }

        // 注意l1和l2都结束后，可能会产生进位，需要创建新节点链接到末尾
        if (surplus > 0)
        {
            ListNode* node = new ListNode(1);
            surplus = 0;
            sumTail->next = node;
            sumTail = node;
        }
        
        return sumHead->next; // 头节点为空，返回头节点的下一个节点
    }
};