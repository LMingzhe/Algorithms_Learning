#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::cin;
using std::cout;
using std::endl;

/// @brief 这道题可以参考代码随想录哈希表中的四书相加题目
///        计算行列式，本质上就是找到两个乘积值相减能得到目标值
///        两层循环求所有可能的乘积值，用unordered_map存储，边求乘积值边搜索即可求解
class Solution
{
public:
    vector<int> constructDeterminant(int x)
    {
        // 用于保存结果，行列式从左到右、从上到下依次对应下标 0 1 2 3
        vector<int> result(4,0);
        unordered_map<int, std::pair<int, int>> map; // 保存乘积，用于搜索
        for (int i = 1; i < 20; i++)
        {
            for (int j = i + 1; j <= 20; j++)
            {
                int r = i * j;
                // 满足行列式的值有两种可能
                if (map.count(r - x)) // 第一种，作为被减数，也就是对应 0 3 位置
                {
                    // cout << "找到 r-x" << endl;
                    result[0] = i;
                    result[3] = j;
                    result[1] = map[r -x].first;
                    result[2] = map[r - x].second;
                    return result;
                }
                else if (map.count(r + x)) // 第二种，作为减数，也就是对应 1 2 位置
                {
                    // cout << "找到 r+x" << endl;
                    result[0] = map[r + x].first;
                    result[3] = map[r + x].second;
                    result[1] = i;
                    result[2] = j;
                    return result;
                }
                // 没有找到符合条件的结果，把当前乘积值和对应数字对保存到map中
                if (!map.count(r))
                {
                    // cout << "加入哈希表" << endl;
                    std::pair<int, int> myPair(i, j);
                    map[r] = myPair;
                }
                // else cout << "啥也没干" << endl;
            }
        }
        return {}; // 没有符合结果，返回空数组
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int x = 0;
    cin >> x;
    vector<int> result;
    result = s.constructDeterminant(x);
    if (result.empty())
    {
        // cout << "empty" << endl;
        cout << "-1" << endl;
        return 0;
    } 
    cout << result[0] << " " << result[1] << endl;
    cout << result[2] << " " << result[3] << endl;
    return 0;
}