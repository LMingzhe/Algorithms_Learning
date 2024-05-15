#include <iostream>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::max;
using std::min;

/// @brief 哈希表题

class Solution
{
public:
    int getMaxCount(vector<int>& cases, vector<int>& parts)
    {
        std::unordered_set<int> set;
        int n = cases.size();
        for (int i = 0; i < n; i++) // 使用set保存所有可能的售价
        {
            for (int j = 0; j < n; j++)
            {
                set.insert(cases[i] + parts[j]);
            }
        }
        int result = 0;
        for (const auto& sum : set)
        {
            std::unordered_map<int, int> map;
            int cnt = 0;
            // map-key 为价格为 ai 的手机壳对应价格为 bi 的手机零件，售价为sum
            // map-value 为完成所有key的组装所需的手机零件个数
            for (int i = 0; i < n; i++) map[sum - cases[i]]++;
            for (int j = 0; j < n; j++)
            {
                // 对应的价格的零件数量大于0，即可完成一个手机的组装
                if (map.count(parts[j]) && map[parts[j]] > 0)
                {
                    cnt++;
                    map[parts[j]]--; // 不可重复用，数量要-1
                }
            }
            result = max(result, cnt);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    int cnt;
    cin >> cnt;
    vector<int> cases(cnt);
    vector<int> parts(cnt);
    for (int i = 0; i < cnt; i++)
    {
        cin >> cases[i];
    }    
    for (int i = 0; i < cnt; i++)
    {
        cin >> parts[i];
    } 
    Solution s;
    int result = s.getMaxCount(cases, parts);
    cout << result << endl;
    return 0;
}
