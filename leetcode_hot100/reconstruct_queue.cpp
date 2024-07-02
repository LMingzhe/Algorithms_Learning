#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// leetcode 根据身高重建队列
/// @brief 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
///        每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
///        请你重新构造并返回输入数组 people 所表示的队列。
///        返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

// 时间复杂度 O(n^2) 空间复杂度O(logn)
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) 
        {
            return u[0] < v[0] || (u[0] == v[0]) && u[1] > v[1]; // 第一个关键字升序，第二个关键字降序
        });

        int n = people.size();
        vector<vector<int>> result(n);
        for (const vector<int>& person : people)
        {
            int spaces = person[1] + 1; // 放在第 person[1] + 1 个空位处
            for (int i = 0; i < n; i++)
            {
                if (result[i].empty())
                {
                    spaces--;
                    if (!spaces)
                    {
                        result[i] = person;
                        break;
                    }
                }
            }
        }
        return result;
    }
};