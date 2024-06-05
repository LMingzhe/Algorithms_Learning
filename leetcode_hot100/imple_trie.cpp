#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

/// leetcode 208 实现Trie（前缀树）
/// @brief Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。
///        这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

class Trie
{
private:
    vector<Trie*> children; // 指向子结点的数组，长度为26，即小写英文子母的数量
    bool isEnd; // 标志该节点是否为字符串的结尾

    // 查找前缀，存在则返回最后一个字符节点，不存在则返回空指针
    Trie* searchPrefix(string prefix)
    {
        Trie* node = this;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word)
    {
        Trie* node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix)
    {
        return this->searchPrefix(prefix) != nullptr;
    }

    ~Trie()
    {
        for (const auto* child: this->children)
        {
            if (child != nullptr) delete child;
        }
    }
};