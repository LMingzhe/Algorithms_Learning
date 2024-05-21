#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

/// leetcode 79 单词搜索
/// @brief 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
///        单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

// 深度优先搜索+回朔
class Solution
{
private:
    vector<std::pair<int, int>> directions // 相邻位置
    {
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0}
    };
    // 深优搜索
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, 
                        int row, int col, string word, int k)
    {
        if (board[row][col] != word[k]) return false; // 子母不相等直接返回false
        if (k == word.length() - 1) return true; // 找到word，返回true
        visited[row][col] = true; // 标记已经访问过
        for (const auto& s : directions) // 向相邻位置搜索
        {
            int newrow = row + s.first;
            int newcol = col + s.second;
            // 检查访问位置的合法性
            if (newrow >= 0 && newrow < board.size() && newcol >= 0 && newcol < board[0].size())
            {
                if (!visited[newrow][newcol])
                {
                    bool flag = dfs(board, visited, newrow, newcol, word, k + 1);
                    if (flag) return true;
                }
            }
        }
        visited[row][col] = false; // 回朔
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int row = board.size();
        int col = board[0].size();
        // 用于标记每个位置是否访问过，避免遍历相邻位置时重复访问
        vector<vector<bool>> visited(row, vector<bool>(col, false)); 
        // 从网格上的每一个位置出发分别做深度优先搜索
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                bool flag = dfs(board, visited, i, j, word, 0);
                if (flag) return true;
            }
        }
        return false;
    }
};