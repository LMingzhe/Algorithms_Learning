#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <numeric>
#include <cstddef>

using std::vector;
using std::string;
using std::sort;

/// leetcode 49 字母异位词分组
/// @brief 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

// 排序
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::unordered_map<string, vector<string>> map;
        for (const auto& str : strs)
        {
            string key  = str;
            sort(key.begin(), key.end());
            map[key].emplace_back(str);
        }
        vector<vector<string>> result;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            result.emplace_back(it->second);
        }
        return result;
    }
};

// 计数，最先想到的也是这个，但是需要自定义对数组的哈希函数，比较复杂
class Solution_v2
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = std::hash<int>{}] (const std::array<int, 26>& arr) -> std::size_t
        {                                              // 将一个名为fn的变量捕获为一个哈希函数对象，该对象用于计算数组中每个元素的哈希值
            return std::accumulate(
            arr.begin(), arr.end(), 0u, [&](std::size_t acc, int num)
                    {                                                       // acc是累加器，保存前面元素的累积结果
                                                                            // num 是当前处理的数组元素
                        return (acc << 1) ^ fn(num); // 通过将累加器左移一位并与当前元素的哈希值异或运算，将当前元素的哈希值合并到累加器中
                    }
                );
        };

        std::unordered_map<std::array<int, 26>, vector<string>, decltype(arrayHash)> map(0, arrayHash);
        for (const string& str : strs)
        {
            std::array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; i++)
            {
                counts[str[i] - 'a']++;
            }
            map[counts].emplace_back(str);
        }
        vector<vector<string>> result;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            result.emplace_back(it->second);
        }
        return result;
    }
};