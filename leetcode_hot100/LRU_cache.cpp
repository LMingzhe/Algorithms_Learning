#include <iostream>
#include <unordered_map>

/// leetcode 146 LRU缓存
/// @brief LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
///        int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
///        void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
///        如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
///        函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

struct Node
{
    int _key, _value;
    Node* _pre;
    Node* _next;
    Node() : _key(0), _value(0), _pre(nullptr), _next(nullptr) {}
    Node(int key, int value) : _key(key), _value(value), _pre(nullptr), _next(nullptr) {}
    Node(int key, int value, Node* pre, Node* next) : _key(key), _value(value), _pre(pre), _next(next) {}
};

class LRUCache
{
private:
    int _capacity;
    Node* _head;
    Node* _tail;
    size_t _size;
    std::unordered_map<int, Node*> map;
public:
    LRUCache(int capacity)
    {
        _capacity = capacity;
        _size = 0;
        _head = new Node();
        _tail = new Node();
        _head->_next = _tail;
        _tail->_pre  = _head;
    }

    int get(int key)
    {
        if (!map.count(key)) return -1;
        remove( map[key]);
        insert( map[key]);
        return map[key]->_value;
    }

    void put(int key, int value)
    {
        if (map.count(key))
        {
            map[key]->_value = value;
            remove(map[key]);
            insert(map[key]);
        } else {
            if (_size == _capacity)
            {
                Node* removeNode = _tail->_pre;
                remove(removeNode);
                map.erase(removeNode->_key); // note 在表中删除被移除节点的key-value
                delete removeNode;
                removeNode = nullptr;
                _size--;
            }
            Node* newNode = new Node(key, value);
            insert(newNode); 
            map[key] = newNode; // 记得存储到哈希表中
            _size++;
        }
    }

    void remove(Node* node) // 从双向链表中移除节点
    {
        node->_pre->_next = node->_next;
        node->_next->_pre = node->_pre;
    }

    void insert(Node* node) // 在双向链表头部插入节点
    {
        node->_next = _head->_next;
        node->_pre = _head;
        _head->_next = node;
        node->_next->_pre = node;
    }
};