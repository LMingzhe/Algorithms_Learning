#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int inf = 1e6;

/// @brief 广度优先搜索

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(m, vector<int>(n));
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dis(m, vector<int>(n, inf));
    dis[x][y] = 0; // 初始化
    queue<pair<int, int>> que;
    que.push(pair<int, int>(x, y));

    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = cur.first + dir[i][1];
            int newY = cur.second + dir[i][0];
            if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[cur.first][cur.second] == 0) continue;
            // 只有响应时间不是最小的才会被更新，所以不会无限循环重复搜索
            if (dis[newX][newY] > dis[cur.first][cur.second] + grid[cur.first][cur.second])
            {
                dis[newX][newY] = dis[cur.first][cur.second] + grid[cur.first][cur.second];
                que.push(pair<int, int>(newX, newY));
            }
        }
    }
    
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0) continue;
            if (dis[i][j] == inf)
            {
                cout << -1 << endl;
                return 0;
            }
            result = max(result, dis[i][j]);
        }
    }
    cout << result << endl;

    return 0;
}

