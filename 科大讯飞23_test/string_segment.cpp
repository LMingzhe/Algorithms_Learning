#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// @brief 将字符串按连续相同字符分割为若干子串，再对子串进行处理即可
class Solution
{
public:
    // 处理分割出的子串
    void dealString(string& subString, vector<string>& result)
    {
        if (subString.length() % 2 != 0) // 子串长度为奇数，可直接作为结果
        {
            result.push_back(subString);
        } 
        else // 若子串长度为偶数，则将前三个字符作为一个子串，剩下的其他字符作为另一个子串
        {
            string sub1 = subString.substr(0, 3);
            string sub2 = subString.substr(3, subString.length() - 3);
            result.push_back(sub1);
            result.push_back(sub2);
        }
    }
    // 按连续相同字符分割出若干子串
    vector<string> stringSegment(string& str)
    {
        bool flag = true; // 标志是否开始一个新的子串
        int same = 1; // 连续相同字符计数器
        vector<string> result;
        for (int i = 0; i < str.length(); i++)
        {
            if (flag)
            {
                // 开始分割新子串时，如果不满足连续三个相同的原则，则可以直接返回空，表示失败
                if ((i + 2) >= str.length() || str[i] != str[i + 2]) return {};
                else
                {
                    // 满足连续三个相同的原则，可以直接跳到第三个字符
                    same = 3;
                    i = i + 2;
                }
            }
            flag = false;
            // 当前字符与下一个字符相等，same+1
            if ((i + 1) < str.length() && str[i] == str[i + 1])
            {
                same++; 
            }
            else // 不相等，说明当前子串在i处结束
            {
                // 子串长度小于6且不等于3，怎么分都不满足至少3个且奇数的条件，返回空表示失败
                if (same < 6 && same != 3) return {};
                string subString;
                subString = str.substr(i - same + 1, same); // 从原字符串分割出当前子串
                dealString(subString, result);
                flag = true; // 重置
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    int length;
    cin >> length;
    string str = "";
    while (length--)
    {
        char c;
        cin >> c;
        str += c;
    }
    Solution s;
    vector<string> result = s.stringSegment(str);
    if (result.empty())
    {
        cout << "-1" << endl;
    }
    else
    {
        for (int i = 0; i < result.size(); i++)
        {
            if (i == result.size() - 1) cout << result[i] << endl;
            else cout << result[i] << " ";
        }
    }
    return 0;
}
