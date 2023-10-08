#include <iostream>
#include <string>
#include <unordered_map>

///leetcode 383 赎金信
/// @brief 给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。
///        如果可以构成，返回 true ；否则返回 false。(假设均为小写字母)
///            时间复杂度: O(n) 空间复杂度: O(1)


class Solution
{
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        int record[26] = {0};
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }
        
        for (int i = 0; i < magazine.size(); i++)
        {
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.size(); j++)
        {
            record[ransomNote[j] - 'a']--;
            if (record[ransomNote[j] - 'a'] < 0)
            {
                return false;
            }
        }

        return true;
    }
};

// 哈希map解法，比数组解法更费时费空间
class Solution2
{
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        std::unordered_map<char, int> map;
        for (auto c : magazine)
        {
            map[c]++;
        }
        for (auto cc : ransomNote)  
        {
            map[cc]--;
            if (map[cc] < 0)
            {
                return false;
            }
            
        }
        return true;
    }
};