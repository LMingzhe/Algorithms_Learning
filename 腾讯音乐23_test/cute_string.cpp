#include <iostream>
#include <string>
#include <vector>

using namespace std;

// fixme 迭代超内存 递归超时间。。。

const int MOD = 1000000007;
int result = 0;
bool isCuteString(const string& s)
{
    if (s.find("red") != string::npos) return false;
    string subStr = "red";
    int j = 0;
    for (int i = 0; i < s.size() && j < subStr.size(); i++)
    {
        if (s[i] == subStr[j]) j++;
    }
    return j == subStr.size();
}

void enumerateStrings(string current, int n)
{
    if (current.size() == n)
    {
        if (isCuteString(current))
        {
            result++;
            result = result % MOD;
        } 
        return; 
    }
    enumerateStrings(current + "r", n);
    enumerateStrings(current + "e", n);
    enumerateStrings(current + "d", n);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    enumerateStrings("", n);
    cout << result << endl;
    return 0;
}