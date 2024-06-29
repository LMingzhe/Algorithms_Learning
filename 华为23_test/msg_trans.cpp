#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs()
{

}

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
    vector<vector<int>> dp(m, vector<int>(n, 0));
    vector<vector<bool>> confirmed(m, vector<bool>(n, false));
    
    return 0;
}

