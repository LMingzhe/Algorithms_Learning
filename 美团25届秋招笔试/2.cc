#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MyComp
{
public:
    bool operator()(const string& l, const string& r)
    {
        return l.length() < r.length();
    }
};

int minCount(const vector<string>& pw_vec, const string& pw_true)
{
    string pre;
    int cnt = 0;
    for (const auto& pw : pw_vec)
    {
        if (pre == pw) continue;
        ++cnt;
        pre = pw;
        if (pw.size() == pw_true.size()) break;
    }
    return cnt;
}

int maxCount(const vector<string>& pw_vec, const string& pw_true)
{
    string pre;
    int cnt = 0;
    for (int i = 0; i < pw_vec.size(); ++i)
    {
        if (pre == pw_vec[i] || pw_vec[i] == pw_true) continue;
        ++cnt;
        pre = pw_vec[i];
        if (pw_vec[i].size() > pw_true.size()) break;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string pw_true;
    cin >> pw_true;
    vector<string> pw_vec;
    while (n--)
    {
        string pw;
        cin >> pw;
        pw_vec.push_back(pw);
    }
    sort(pw_vec.begin(), pw_vec.end(), MyComp());
    // cout << " =============== " << endl;
    // for (auto str : pw_vec)
    // {
    //     cout << str << endl;
    // }
    int minCnt = minCount(pw_vec, pw_true);
    int maxCnt = maxCount(pw_vec, pw_true);
    cout << minCnt << " " << maxCnt << endl;

    return 0;
}
