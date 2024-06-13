#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/// @brief 枚举所有可能的矩阵，连通数量计算参考leetcode 200

// 上下左右四个方向数组
int direct[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

// 深度优先搜索
void dfs(const vector<vector<char>>& matrix, vector<vector<bool>>& visited, int x, int y, 
            const int& rows, const int& cols, const char& ch)
{
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + direct[i][0];
        int nextY = y + direct[i][1];
        if (nextX < 0 || nextX >= rows || nextY < 0 || nextY >= cols)
        {
            continue;
        }
        if (!visited[nextX][nextY] && matrix[nextX][nextY] == ch)
        {
            visited[nextX][nextY] = true;
            dfs(matrix, visited, nextX, nextY, rows, cols, ch);
        }
    }
}

/// @brief 思路：构建所有可能的棋盘，使用dfs求连通数（构建visit数组表示访问），取所有棋盘中连通数最小值
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string s;
    while (n--)
    {
        char ch;
        cin >> ch;
        s.push_back(ch);
    }
    int len = s.length();
    // cout << s << endl;
    int result = std::numeric_limits<int>::max();
    // 枚举所有可能的矩阵
    for (int rows = 1; rows <= len; rows++)
    {
        if (len % rows == 0) // rows * cols = len 能整除
        {
            int cols = len / rows;
            // cout << "可以构成 " << rows << " * " << cols << " 的矩阵: " << endl;
            vector<vector<char>> matrix(rows, vector<char>(cols));
            int index = 0;
            // 构建矩阵
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    matrix[i][j] = s[index];
                    index++;
                }
            }
            // // note 打印矩阵
            // for (int i = 0; i < rows; i++)
            // {
            //     for (int j = 0; j < cols; j++)
            //     {
            //         cout << matrix[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // // note 
            // 记录节点是否被访问
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            int connNum = 0;
            // dfs计算连通数
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (!visited[i][j])
                    {
                        visited[i][j] = true;
                        connNum++;
                        char ch = matrix[i][j];
                        dfs(matrix, visited, i, j, rows, cols, ch);
                    }
                }
            }
            // cout << "本次 connNum: " << connNum << endl;
            result = min(result, connNum);
        }
    }
    cout << result << endl;
    return 0;
}