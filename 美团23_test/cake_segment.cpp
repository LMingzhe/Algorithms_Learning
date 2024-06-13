#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

/// @brief 根据题意，只能按行横刀切 or 按列纵刀切，枚举所有可能，求最小值即可

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> weight(n, vector<int>(m)); // weight数组表示美味度
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            weight[i][j] = num;
        }
    }

    vector<long long> rosSum(n); // 存储每一行weight总和
    vector<long long> colSum(m); // 存储每一列weight总和
    long long weightSum = 0; // 所有weight总和
    for (int i = 0; i < n; i++) // 求每一行weight总和
    {
        rosSum[i] = accumulate(weight[i].begin(), weight[i].end(), 0);
        weightSum += rosSum[i];
    }
    for (int i = 0; i < m; i++) // 求每一列weight总和
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += weight[j][i];
        }
        colSum[i] = sum;
    }

    // 两种不同的切法
    long long result = std::numeric_limits<long long>::max(); // 存储最终结果
    for (int i = 0; i < n - 1; i++) // 横刀切
    {
        long long oneHalf = 0;
        for (int j = 0; j <= i; j++)
        {
            oneHalf += rosSum[j];
        }
        long long diff = abs(oneHalf - (weightSum - oneHalf));
        result = min(result, diff);
    }
    for (int i = 0; i < m - 1; i++) // 纵刀切
    {
        long long oneHalf = 0;
        for (int j = 0; j <= i; j++)
        {
            oneHalf += colSum[j];
        }
        long long diff = abs(oneHalf - (weightSum - oneHalf));
        result = min(result, diff);
    }
    cout << result << endl;
    return 0;
}
