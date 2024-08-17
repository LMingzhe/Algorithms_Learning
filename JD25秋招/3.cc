#include <bits/stdc++.h>

using namespace std;

/// @brief 图深度优先遍历 AC50% 其他超时

struct Edge
{
    int to;
    int val;
    Edge(int to, int val) : to(to), val(val) {}
};

void dfs(vector<list<Edge>>& grid, int& result, int comsume, int& a, int cur, int& n)
{
    if (comsume > a) return;
    if (cur == n && comsume == a)
    {
        ++result;
        return;
    }
    for (const auto& edge : grid[cur])
    {
        int next = edge.to;
        int val = edge.val;
        if (comsume + val <= a)
        {
            dfs(grid, result, comsume + val, a, next, n);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, m, a;
    cin >> n >> m >> a;
    vector<list<Edge>> grid(n + 1);
    while (m--)
    {
        int ori, to, val;
        cin >> ori >> to >> val;
        grid[ori].push_back(Edge(to, val));
    }
    int result = 0;
    dfs(grid, result, 0, a, 1, n);

    if (result >= 20220201)
    {
        cout << "All roads lead to Home!" << endl;
        cout << (result % 20220201) << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
