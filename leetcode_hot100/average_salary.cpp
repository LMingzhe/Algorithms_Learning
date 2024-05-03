#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;

/// leetcode 1491 去掉最低工资和最高工资后的工资平均值
/// @brief salary ，数组里每个数都是 唯一 的，其中 salary[i] 是第 i 个员工的工资。
/// 请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。
/// 时间复杂度O(n) 空间复杂度O(1) 属于找自信的题

class Solution
{
public:
    int finMax(vector<int>& salary)
    {
        int max = salary[0];
        for (int i = 1; i < salary.size(); i++)
        {
            if (salary[i] > max) max = salary[i];
        }
        return max;
    }
    int finMin(vector<int>& salary)
    {
        int min = salary[0];
        for (int i =  1; i < salary.size(); i++)
        {
            if (salary[i] < min) min = salary[i];
        }
        return min;
    }
    double average(vector<int>& salary)
    {
        int max = finMax(salary);
        int min = finMin(salary);
        double sum = std::accumulate(salary.begin(), salary.end(), -max-min);
        return sum / (salary.size() - 2);
    }
};