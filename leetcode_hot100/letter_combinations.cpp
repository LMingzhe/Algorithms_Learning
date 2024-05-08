#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;

/// leetcode 17 电话号码的子母组合
/// @brief 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
///        回朔穷举，画出树即可求解

class Solution
{
private:
    std::unordered_map<char, string> map
    {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> result;
    string combin;

    void backtracking(const string& digits, int index)
    {
        if (combin.size() == digits.size())
        {
            result.push_back(combin);
            return;
        }
        char digit = digits[index]; // 每次深度遍历都要换一个树字，所以需要index
        // 遍历数字对应的字符串中的字符
        for (int i = 0; i < map[digit].size(); i++) 
        {
            combin.push_back(map[digit][i]);
            backtracking(digits, index + 1); // 每次深度+1都要换一个数字的字符，所以index+1
            combin.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) 
    {
        result.clear();
        combin.clear();
        if (digits.size() == 0) return {};
        backtracking(digits, 0);
        return result;
    }
};