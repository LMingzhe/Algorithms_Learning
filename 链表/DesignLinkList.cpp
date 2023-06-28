#include <iostream>
#include <vector>

using namespace std;

/// leetcode 707
/// @brief 设计链表，实现功能

class MyLinkedList
{
public:
    // 定义节点结构体
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode(int x):val(x), next(nullptr) {}
    };

    // 初始化链表
    MyLinkedList()
    {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    // 获取到第index个节点数值，如果index是非法数值则直接返回-1，注意index是从0开始的，第0个节点就是头节点
    int get(int index)
    {
        if (index > (_size - 1) || index < 0)
        {
            return - 1;
        }
        LinkedNode* cur = _dummyHead->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    // 在链表的最前面插入一个节点，插入完成后，新插入的节点为链表的新头节点
    void addAtHead(int val)
    {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // 在链表的最后面添加一个节点
    void addAtTail(int val)
    {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr)    
        {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点
    // 如果index等于链表的长度，则说明是新插入的节点为链表的尾节点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val)
    {
        if (index > _size) return;
        if (index < 0) index = 0;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead->next;
        while (index--)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // 删除第index个节点，如果index大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index)
    {
        if (index >= _size || index < 0) return;
        LinkedNode* cur = _dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        // delete命令只是释放了tmp指针原本所指的那部分内存
        // 被delete后的指针tmp的值（地址）并非就是null，而是随机值，也就是被delete后，
        // 如果不加上一句tmp=nullptr，tmp会成为乱指的野指针
        // 如果之后的程序不小心使用了tmp，就会指向难以预想的内存空间
        tmp = nullptr;
        _size--;
    }

    // 打印链表
    void printLinkedList()
    {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr)    
        {
            cout << cur->next->val << " ";
            cur->next;
        }
        cout << endl;
    }

private:
    int _size;
    LinkedNode* _dummyHead;
};