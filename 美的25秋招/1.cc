#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    std::unordered_set<char> uset;
    string newStr;
    for (int i = 0; i < str.length(); ++i)
    {
        char ch = std::tolower(str[i]);
        if (uset.find(ch) != uset.end())
        {
            // cout << "找到相同字母跳过" << endl;
            continue;
        } else {
            // cout << "哈希表中没有，加入新字符串" << endl;
            uset.insert(ch);
            newStr.push_back(str[i]);
        }

    }

    cout << newStr << endl;

    return 0;
}
