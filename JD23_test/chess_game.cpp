#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/// @brief 逻辑题

// 判断某位置的棋子是否被夹住
bool isClamp(const char& cur, const char& ch1, const char& ch2)
{
    if ((cur == 'o' && ch1 == '*' && ch2 == '*') || 
            (cur == '*' && ch1 == 'o' && ch2 == 'o'))
    {
        return true;
    }
    return false;
}

// 判断输赢
string jude(vector<vector<char>>& chessBoard)
{
    int black = 0; // 表示吃了多少颗白子
    int white = 0; // 表示吃了多少颗黑子
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (chessBoard[i][j] == '.') continue;
            // 横向判断
            int left = j - 1;
            int right = j + 1;
            if (left >= 0 && right < 3)
            {
                if (isClamp(chessBoard[i][j], chessBoard[i][left], chessBoard[i][right]))
                {
                    if (chessBoard[i][j] == 'o') black++;
                    else white++;
                }
            }
            // 纵向判断
            int up = i - 1;
            int down = i + 1;
            if (up >= 0 && down < 3)
            {
                if (isClamp(chessBoard[i][j], chessBoard[up][j], chessBoard[down][j]))
                {
                    if (chessBoard[i][j] == 'o') black++;
                    else white++;
                }
            }
        }
    }
    // 判断
    if (black == 0 && white == 0 || black > 0 && white > 0)
    {
        return "draw";
    } else if (black == 0 && white > 0) {
        return "yukan";
    } else {
        return "kou";
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    vector<vector<char>> chessBoard(3, vector<char>(3));
    while (t--)
    {
        for (int i = 0; i < 3; i++)
        {
            string line;
            cin >> line;
            for (int j = 0; j < line.length(); j++)
            {
                chessBoard[i][j] = line[j];
            }
        }
        string result = jude(chessBoard);
        cout << result << endl;
    }
    return 0;
}
