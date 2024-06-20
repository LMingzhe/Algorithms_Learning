#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/// @brief 逻辑题

// 计算还有多少病症
int count(const string& state)
{
    int cnt = 0;
    for (const auto& ch : state)
    {
        if (ch == '1') cnt++;
    }
    return cnt;
}

// 判断 当前状态，药贴状态，副作用状态 三种状态叠加后是否得病
char isSick(char cur, char heal, char sideEffect)
{
    int c = cur - '0';
    int h = heal - '0';
    int se = sideEffect - '0';
    if (!(c || se) || (c && heal == '1')) // 原来不得病且副作用不致病 or 原来得病且药贴能致病
    {
        return '0';
    } else { // 其他情况均会得病    
        return '1';
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string curState; // 当前状态
    cin >> curState;
    int m;
    cin >> m;
    vector<string> heal;
    vector<string> sideEffect;
    for (int i = 0; i < m; i++)
    {
        string h;
        cin >> h;
        heal.push_back(h);
        string se;
        cin >> se;
        sideEffect.push_back(se);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int u; // 吃第u副药
        cin >> u;
        u -= 1; // 注意数组下标
        for (int i = 0; i < n; i++)
        {
            // 更新吃药后的状态
            curState[i] = isSick(curState[i], heal[u][i], sideEffect[u][i]);
        }
        int result = count(curState);
        cout << result << endl;
    }
    return 0;
}
