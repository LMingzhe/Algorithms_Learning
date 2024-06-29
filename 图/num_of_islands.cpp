#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

/// leetcode 200 岛屿数量
/// @brief 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
///        岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
///        此外，你可以假设该网格的四条边均被水包围。

// 深度优先搜索
class Solution
{
public:
    int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y)
    {
        for (int i = 0; i < 4; i++)
        {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
            if (!visited[nextx][nexty] && grid[nextx][nexty] == '1')
            {
                visited[nextx][nexty] = true;
                dfs(grid, visited, nextx, nexty);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false)); // 记录是否访问过
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    result++;
                    visited[i][j] = true;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return result;
    }
};

// 广度优先搜索
class Solution
{
public:
    int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visisted, int x, int y)
    {
        queue<std::pair<int, int>> que;
        que.push({x, y});
        visisted[x][y] = true; // 只要加入队列立刻标记
        while (!que.empty())
        {
            std::pair<int, int> x_y = que.front();
            que.pop();
            int curX = x_y.first;
            int curY = x_y.second;
            for (int i = 0; i < 4; i++)
            {
                int nextX = curX + dir[i][0];
                int nextY = curY + dir[i][1];
                if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) continue;
                if (!visisted[nextX][nextY] && grid[nextX][nextY] == '1')
                {
                    que.push({nextX, nextY}); 
                    visisted[nextX][nextY] = true; // 只要加入队列立刻标记
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visisted(n, vector<bool>(m, false));
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visisted[i][j] && grid[i][j] == '1')
                {
                    result++;
                    visisted[i][j] = true;
                    bfs(grid, visisted, i, j);
                }
            }
        }
        return result;
    }
};
