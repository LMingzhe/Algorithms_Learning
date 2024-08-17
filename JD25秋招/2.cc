#include <bits/stdc++.h>

using namespace std;

/// @brief AC12.5% 其他超时

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    string height_1;
    string height_2;
    cin >> height_1 >> height_2;
    if (n > m)
    {
        swap(height_1, height_2);
    }
    int len1 = height_1.length(); // 短
    int len2 = height_2.length(); // 长
    int index_1 = 0;
    int index_2 = 0;
    int pre_index_2 = 0;
    bool flag = true;
    while (index_1 < len1 && index_2 < len2)
    {
        string s1;
        s1.push_back(height_1[index_1]);
        string s2;
        s2.push_back(height_2[index_2]);
        if (stoi(s1) + stoi(s2) <= 3)
        {
            ++index_1;
            ++index_2;
            if (flag)
            {
                pre_index_2 = index_2;
                flag = false;
            }
        } else {
            index_1 = 0;
            index_2 = pre_index_2 + 1;
            flag = true;
        }
    }
    if (index_2 < len2)
    {
        cout << len2 << endl;
    } else {
        cout << len2 + len1 - index_1 - 1 << endl;
    }
    return 0;
}
