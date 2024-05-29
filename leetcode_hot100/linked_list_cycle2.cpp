#include <iostream>
#include <unordered_set>
#include "ListNode_def.h"

using std::unordered_set;

/// leetocode 142 环形链表2
/// @brief 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

// 时间复杂度O(n) 空间复杂度O(1) 与141解法一致
class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        unordered_set<ListNode*> set;
        while (head != nullptr)
        {
            if (set.count(head))
            {
                return head;
            }
            set.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

// 时间复杂度O(n) 空间复杂度O(1)
class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head; // NOTE 快指针这里开始应指向head，而不是像141一样指向head->next
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode* ptr = head;
                while (ptr != slow) // 当快慢节点相遇时，定义一个指向头结点的指针ptr，
                {                   // ptr和慢指针同时走，两者相遇处即为环入口节点
                    slow = slow->next;
                    ptr = ptr->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};