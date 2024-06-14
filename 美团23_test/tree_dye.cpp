#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

/// @brief 目前想到的只有回朔列举所有可能
// fixme 还没昨晚，后续修改补充，是否能一个backtracking就解决？

bool ifPerfectSquare(int x, int y)
{
    int squareRoot = sqrt(x * y);
    return squareRoot * squareRoot == x * y;
}

void backtracking(int index, int& result, vector<bool>& redNode, int n, 
                    unordered_map<int, int>& mapWeight, unordered_map<int, vector<int>>& mapConn)
{
    // 终止条件
    
    // 
    if (!redNode[index])
    {
        for (const int& neighbor : mapConn[index])
        {
            if (!redNode[neighbor] && ifPerfectSquare(index, neighbor))
            {
                redNode[index] = true;
                redNode[neighbor] = true;
                result += 2;
                // backtracking(neighbor,)
            }
        }
    }

}

int main(int argc, char const *argv[])
{
    unordered_map<int, int> mapWeight;
    unordered_map<int, vector<int>> mapConn;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int weight;
        cin >> weight;
        mapWeight[i] = weight;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        mapConn[u].push_back(v);
        mapConn[v].push_back(u);
    }
    vector<bool> redNode(n, false);
    int result = 0;
    // 回朔 ？贪心 ？ 动态 ？
    for (int i = 0; i < n; i++)
    {
        int redNum = 0;
        redNode.resize(n, false);
        backtracking(i, redNum, redNode, n, mapWeight, mapConn);
        result = min(result, redNum);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     if (!redNode[i])
    //     {
    //         for (const int& neighbor : mapConn[i])
    //         {
    //             if (!redNode[neighbor] && ifPerfectSquare(mapWeight[i], mapWeight[neighbor]))
    //             {
    //                 // 标记染红
    //                 redNode[i] = true;
    //                 redNode[neighbor] = true;
    //                 // 个数++
    //                 result += 2;
    //                 break;
    //             }
    //         }
    //     }
    // }
    cout << result << endl;
    return 0;
}
