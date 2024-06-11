#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/// @brief 拓扑排序
// fixme 这道题无法全部AC，不知道为啥，找了很久没找出问题在哪

int main(int argc, char const *argv[])
{
    int fileNums, depends;
    cin >> fileNums >> depends;
    vector<int> inDegree(fileNums, 0); // 记录每个节点的入度数
    vector<vector<int>> edges(fileNums, vector<int>()); // 记录边，即依赖关系
    while (depends--)
    {
        int S, T;
        cin >> S >> T; // S->T T文件依赖于S
        edges[S].push_back(T); // S出度指向
        inDegree[T]++; // T的入度+1
    }

    queue<int> que;
    int visited = 0; // 记录已访问节点个数
    for (int i = 0; i < fileNums; i++)
    {
        if (inDegree[i] == 0)
        {
            que.push(i);
            visited++;
        }
    }

    vector<int> result;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        result.push_back(cur);
        for (const int& v : edges[cur])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                que.push(v);
                visited++;
            }
        }
    }

    if (visited == fileNums)
    {
        for (int i = 0; i < fileNums; i++)
        {
            if (i == fileNums - 1) cout << i << endl;
            else cout << i << " ";
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
