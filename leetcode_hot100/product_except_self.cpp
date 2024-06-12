#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

/// leetcode 238 除自身以外数组的乘积
/// @brief 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
///        题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
///        请不要使用除法，且在 O(n) 时间复杂度内完成此题。

// 左右乘积列表 时间复杂度O(n) 空间复杂度O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        size_t n = nums.size();
        vector<int> answer(n);
        vector<int> L(n); // nums[i] 左侧所有元素乘积
        L[0] = 1; // nums[0] 左侧没有元素，取1
        vector<int> R(n); // nums[i] 右侧所有元素乘积
        R[n - 1] = 1; // nums[n - 1] 右侧没有元素，取1

        for (int i = 1; i < n; i++) // 计算各个元素的左侧所有元素乘积
        {
            L[i] = L[i - 1] * nums[i -1];
        }
        for (int i = n - 2; i >=0; i--) // 计算各个元素的右侧所有元素乘积
        {
            R[i] = R[i + 1] * nums[i + 1];
        }

        // 对于索引 i，除 nums[i] 之外其余各元素的乘积就是左侧所有元素的乘积乘以右侧所有元素的乘积
        for (int i = 0; i < n; i++)
        {
            answer[i] = L[i] * R[i];
        }

        return answer;
    }
};

// 优化后空间复杂度为O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        size_t n = nums.size();
        vector<int> answer(n); 

        // 使用输出数组当作L数组
        answer[0] = 1;
        for (int i = 1; i < n; i++)
        {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        // 动态维护R，表示右侧乘积
        int R = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            answer[i] = answer[i] * R;
            R = R * nums[i];
        }

        return answer;
    }
};


// 超内存了
class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        size_t n = nums.size();
        vector<int> answer(n);
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp = nums;
            temp[i] = 1;
            map[i] = temp;
        }
        for (int i = 0; i < n; i++)
        {
            answer[i] = accumulate(map[i].begin(), map[i].end(), 1, std::multiplies<int>());
        }
        return answer;
    }
};