#include <iostream>
#include <vector>
#include <algorithm>
#include "ListNode_def.h"

/// leetcode 148 排序链表
/// @brief 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

// 归并排序
class Solution
{
public:
    // 有序合并链表
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* dummyHead = new ListNode(0); // 虚拟头结点
        ListNode* tmp = dummyHead;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr)
        {
            if (temp1->val <= temp2->val)
            {
                tmp->next = temp1;
                temp1 = temp1->next;
            } else {
                tmp->next = temp2;
                temp2 = temp2->next;
            }
            tmp = tmp->next;
        }
        if (temp1 != nullptr)
        {
            tmp->next = temp1;
        } else if (temp2 != nullptr)
        {
            tmp->next = temp2;
        }
        return dummyHead->next;
    }
    ListNode* sortList(ListNode* head, ListNode* tail)
    {
        if (head == nullptr) return head;
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail) // 快慢指针，找到中间节点，分治法
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) fast = fast->next;
        }
        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }
    ListNode* sortList(ListNode* head)
    {
        return sortList(head, nullptr);
    }
};

// 有点硬核，直接把节点的值取出来存储到vector，使用sort进行排序，再给回原链表
// 没有任何链表插入操作。。leetcode跑的结果比题解时间和空间都要优 :)
class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        std::vector<int> valVec;
        ListNode* tmp = head;
        ListNode* tmp2 = head;
        while (tmp != nullptr)
        {
            valVec.push_back(tmp->val);
            tmp = tmp->next;
        }
        std::sort(valVec.begin(), valVec.end());
        for (const int& val : valVec)
        {
            tmp2->val = val;
            tmp2 = tmp2->next; 
        }
        return head;
    }
};