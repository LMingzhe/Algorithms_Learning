#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

/// @brief A* 算法 bfs+启发函数

int moves[1001][1001];
int dir[8][2] = {-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2};
int b1, b2;
// F = G + H
// G = 从起点到该节点路径消耗
// H = 该节点到终点的预估消耗

struct Knight
{
    int x, y;
    int g, h, f;
    // 重载运算符， 从小到大排序
    bool operator < (const Knight& k) const
    {
        return k.f < f;
    }
};

// 优先队列实现小根堆，优先弹出Knight对象中F值最小的对象
priority_queue<Knight> que;

// 启发函数，这里使用欧式距离
int Heuristic(const Knight& k)
{
    // 统一不开根号，这样可以提高精度
    return (k.x - b1) * (k.x - b1) + (k.y - b2) * (k.y - b2);
    // 曼哈顿距离  abs(k.x - b1) + abs(k.y - b2)
    // 切比雪夫距离  max(abs(k.x - b1), abs(k.y - b2))
}

void astart(const Knight& k)
{
    Knight cur, next;
    que.push(k);
    while (!que.empty())
    {
        cur = que.top();
        que.pop();
        if (cur.x == b1 && cur.y == b2) break;
        for (int i = 0; i < 8; i++)
        {
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];
            if (next.x < 1 || next.x > 1000 || next.y < 1 || next.y > 1000) continue;
            if (!moves[next.x][next.y])
            {
                moves[next.x][next.y] = moves[cur.x][cur.y] + 1;

                // 计算F
                next.g = cur.g + 5; // 统一不开根号，这样可以提高精度，马走日，1 * 1 + 2 * 2 = 5
                next.h = Heuristic(next);
                next.f = next.g + next.h;
                que.push(next);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, a1, a2;
    cin >> n;
    while (n--)
    {
        cin >> a1 >> a2 >> b1 >> b2;
        memset(moves, 0, sizeof(moves));
        Knight start;
        start.x = a1;
        start.y = a2;
        start.g = 0;
        start.h = Heuristic(start);
        start.f = start.g + start.h;
        astart(start);
        while (!que.empty()) que.pop();
        cout << moves[b1][b2] << endl;
    }
    return 0;
}
