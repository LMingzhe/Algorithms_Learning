#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

/// leetcode 51 N皇后问题
/// @brief n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击(同一行、列、斜线不能有两个皇后)
///        给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
///        时间复杂度: O(n!) 空间复杂度: O(n)

class Solution
{
private:
    vector<vector<string>> result;
    vector<string> chessborad;

    // 判断当前放置位置是否合法
    bool isValid(int row, int col, vector<string>& chessboard, int n)
    {
        // 检查列
        for (int i = 0; i < row; i++)
        {
            if (chessboard[i][col] == 'Q') return false;
        }

        // 检查135度是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q') return false;
        }

        // 检查45度是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] ==  'Q') return false;
        }

        return true;
    }

    // 回朔是一棵树，树的叶子节点就是需要的结果
    // n是输入棋盘大小，row是当前递归到棋盘第几行，即树的深度，col为当前行的列位置
    void backtracking(int n, int row, vector<string>& chessboard)
    {
        if (row == n)
        {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isValid(row, col, chessboard, n))
            {
                chessboard[row][col] = 'Q';
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        result.clear();
        chessborad.resize(n, string(n, '.'));
        backtracking(n, 0, chessborad);
        return result;
    }
};