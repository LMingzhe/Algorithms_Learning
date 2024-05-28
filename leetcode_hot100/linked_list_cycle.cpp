#include <iostream>
#include <unordered_set>
#include "ListNode_def.h"

using std::unordered_set;

/// leetcode 141 环形链表
/// @brief 给你一个链表的头节点 head ，判断链表中是否有环。

// 哈希表 时间复杂度O(n) 空间复杂度O(n)
class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        // 使用哈希表记录当前节点是否被访问过
        unordered_set<ListNode*> listSet;
        while (head != nullptr)
        {
            if (listSet.count(head))
            {
                return true;
            }
            listSet.insert(head);
            head = head->next;
        }
        return false;
    }
};

// 快慢指针法 时间复杂度(n) 空间复杂度O(1)
class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* slow = head;       // 慢指针
        ListNode* fast = head->next; // 快指针
        while (slow != fast) // 只要存在环，快指针一定会追上慢指针
        {
            if (fast == nullptr || fast->next == nullptr) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};