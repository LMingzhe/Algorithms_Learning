#include <iostream>
#include "ListNode_def.h"

using namespace std;

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;

        // fast先走n步
        while (n-- && fast != nullptr)  
        {
            fast = fast->next;
        }
        fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点

        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // 删除节点，释放内存
        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        tmp = nullptr;

        return dummyHead->next;
    }
};
