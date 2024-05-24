#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int match(string& str, int k)
    {
        if (str.length() < k) return -1;
        // if (k == 1)
        // {
        //     for (char& c : str)
        //     {
        //         if (c == '?') c = '0';
        //     }
        //     return stoi(str);
        // }
        vector<int> indexVce;
        char target = '0';
        int index = str.find(target);
        while (index != std::string::npos)
        {
            indexVce.push_back(index);
            index = str.find('0');
        }
        // todo 替换字符串中的'?'
    }
};

int main(int argc, char const *argv[])
{
    vector<string> strVec;
    vector<int> intVec;
    int cnt;
    cin >> cnt;
    while (cnt--)
    {
        string str;
        int k;
        cin >> str;
        cin >> k;
        strVec.push_back(str);
        intVec.push_back(k);
    }
    Solution s;
    for (int i = 0; i < strVec.size(); i++)
    {
        int result = s.match(strVec[i], intVec[i]);
        cout << result << endl;
    }
    return 0;
}
