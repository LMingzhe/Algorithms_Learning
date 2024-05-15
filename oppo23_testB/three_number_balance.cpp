#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::min;

/// @brief 还是有点不理解题意，何为三数平衡？以下注释为网上资料

class Solution
{
public:
    int threeNumberBalance(int x, int y, int z)
    {
        // 因为任意两个整数的平均数是整数当且仅当这两个整数的奇偶性相同（即都是偶数或都是奇数）。
        // 所以问题就变成了使x, y, z的奇偶性相同的最小操作次数。
        int opCnt = 0;
        // 判断每个数是否为偶数，如果是，则计数器加一
        if (x % 2 == 0) opCnt++;
        if (y % 2 == 0) opCnt++;
        if (z % 2 == 0) opCnt++;
        // 这里的最小操作次数可以是让所有的数都变成偶数，也可以是让所有的数都变成奇数。
        // 要使所有的数都变成偶数，操作次数就是奇数的数量（3 - opCnt），
        // 要使所有的数都变成奇数，操作次数就是偶数的数量（opCnt）。
        // 因此，最小操作次数就是这两者中的最小值。
        return min(opCnt, 3 - opCnt);
    }
};

int main(int argc, char const *argv[])
{
    int x, y, z;
    cin >> x >> y >> z;
    Solution s;
    int result = s.threeNumberBalance(x, y, z);
    cout << result << endl;
    return 0;
}
