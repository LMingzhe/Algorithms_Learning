#include <bits/stdc++.h>

using namespace std;

int direct[8][2] = {0, -1, 0, 1,
                    1, 0, -1, 0,
                    1, 1, -1, -1,
                    -1, 1, 1, -1};

int result = 0;

void dfs(vector<vector<int>>& grid, int curLen, int curX, int curY, int addX, int addY, int rows, int cols)
{
    if (curX < 0 || curX >= rows || curY < 0 || curY >= cols) return;
    if (grid[curX][curY] == 0) return;

    result = max(result, curLen);

    int nextX = curX + addX;
    int nextY = curY + addY;

    dfs(grid, curLen + 1, nextX, nextY, addX, addY, rows, cols);

}

int main(int argc, char const *argv[])
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    string temp;
    int rows, clos;
    getline(ss, temp, ',');
    rows = stoi(temp);
    getline(ss, temp, ',');
    clos = stoi(temp);

    vector<vector<int>> grid(rows, vector<int>(clos, 0));
    for (int i = 0; i < rows; ++i)
    {
        string str;
        getline(cin, str);
        stringstream strs(str);
        string tmp;
        int index = 0;
        while (getline(strs, tmp, ','))
        {
            int flag = stoi(tmp);
            if (flag == 1)
            {
                grid[i][index] = 1;
            }
            ++index;
        }
    }

    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < clos; ++col)
        {
            if (grid[row][col] == 1)
            {
                for (int i = 0; i < 8; ++i)
                {
                    dfs(grid, 1, row, col, direct[i][0], direct[i][1], rows, clos);
                }
            }
        }
    }

    cout << result << endl;
    
    return 0;
}