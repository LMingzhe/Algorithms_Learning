#include <iostream>
#include <vector>
#include "ListNode_def.h"

using namespace std;

/// leetcode 206
/// @brief 反转链表

// 双指针法 时间复杂度O(n) 空间复杂度O(1)
class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur != nullptr)
        {
            temp = cur->next; // 保存一下cur的下一个节点，因为接下来要改变cur->next
            cur->next = pre;  // 翻转操作
            // 更新pre和cur指针
            pre = cur;  
            cur = temp;
        }
        return pre;
    }
};

// 递归法 时间复杂度(n) 空间复杂度(n)
class Solution_v2
{
public:
    ListNode* reverse(ListNode* pre, ListNode* cur)
    {
        if (cur == nullptr) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // 可以和双指针的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur, temp);
    }

    ListNode* reverseList(ListNode* head)
    {
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = nullptr;
        return reverse(nullptr, head);
    }
};

class Sulotion_v3
{
public:
    ListNode* reverse(ListNode* head)
    {
        // 边缘条件判断
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        // 边缘条件判断
        ListNode* last = reverse(head->next);

        // 翻转头节点与第二个节点的指向
        head->next->next = head;
        // 此时的 head 节点为尾节点，next 需要指向 NULL
        head->next = nullptr;

        return last; 
    }
};
