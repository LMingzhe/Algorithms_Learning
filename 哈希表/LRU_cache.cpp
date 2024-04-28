#include <iostream>
#include <vector>
#include <unordered_map>

using std::unordered_map;

/// leetcode 146 LRU缓存
/// @brief LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
///        int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
///        void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
///        如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
///        函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。


// 双向链表定义
struct Node
{
    int _key, _value;
    Node* _pre; 
    Node* _next;
    Node() : _key(0), _value(0), _pre(nullptr), _next(nullptr) {}
    Node(const int& key, int& value) : _key(key), _value(value), _pre(nullptr), _next(nullptr) {}
};

class LRUCache
{
public:
    Node* _head;
    Node* _tail;
    unordered_map<int, Node*> map;  // 哈希表实现O(1)查找
    int _capacity; // LRU容量
    size_t _size;  // 已使用容量

    // 初始化
    LRUCache(int capacity) : _capacity(capacity), _size(0)
    {
        _head = new Node();
        _tail = new Node();
        _head->_next = _tail;
        _tail->_pre = _head;
    }

    int get(int key)
    {
        if (!map.count(key)) return -1;
        Node* node = map[key];
        removeNode(node);
        insertNodeToHead(node);
        return node->_value;
    }

    void put(int key, int value)
    {
        if (map.count(key)) // key存在
        {
            Node* node = map[key];
            node->_value = value;
            removeNode(node);
            insertNodeToHead(node);
        }
        else
        {
            if (_size == _capacity) // 容量达到上限，删除末尾节点再插入新节点
            {
                Node* removedNode = _tail->_pre;
                map.erase(removedNode->_key);
                removeNode(removedNode);
                delete removedNode;
                removedNode = nullptr;
                _size--;
            }
            Node* node = new Node(key, value);
            insertNodeToHead(node);
            map[key] = node;
            _size++;
        }
    }

    // 从链表中删除节点
    void removeNode(Node* node)
    {
        node->_pre->_next = node->_next;
        node->_next->_pre = node->_pre;
    }

    // 在链表头插入节点
    void insertNodeToHead(Node* node)
    {
        node->_next = _head->_next;
        node->_pre = _head;
        _head->_next->_pre = node;
        _head->_next = node;
    }
};