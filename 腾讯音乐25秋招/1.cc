#include <bits/stdc++.h> 

using namespace std;
using ll = long long;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a ListNode类 
     * @return int整型
     */
    int merge(ListNode* a) {
        // write code here
        int cnt = 0;
        ll pre = a->val;
        ListNode* preNode = a;
        ListNode* cur = a->next;
        while (cur != nullptr)
        {
            if (cur->val == 0)
            {
                if (pre == 0)
                {
                    pre += cur->val;
                    preNode->next = cur->next;
                    ListNode* temp = cur;
                    cur = preNode;
                    temp->next = nullptr;
                    ++cnt;
                } else {
                    pre = cur->val;
                    preNode = cur;
                }
                cur = cur->next;
            } else {
                if (pre != 0)
                {
                    pre += cur->val;
                    preNode->next = cur->next;
                    ListNode* temp = cur;
                    cur = preNode;
                    temp->next = nullptr;
                    ++cnt;
                } else {
                    pre = cur->val;
                    preNode = cur;
                }
                cur = cur->next;
            }
        }
        return cnt;
    }
};