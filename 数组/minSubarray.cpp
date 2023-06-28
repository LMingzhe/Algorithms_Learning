#include <iostream>
#include <vector>

using namespace std;

/// leetcode 209
///@brief 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
///    时间复杂度：O(n) 空间复杂度：O(1)
///

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};

int main(int argc, char **argv) {
    Solution sol;
    vector<int> nums{2, 3, 1, 2, 4, 3};
    cout << "原数组为：";
    for (auto it = nums.begin(); it != nums.end(); it++) {
        if (it == nums.end() - 1) {
            cout << *it << endl;
        } else {
            cout << *it << ", ";
        }
    }
    int s = 7;
    int result = sol.minSubArrayLen(s, nums);
    cout << "和为" << s << "的长度最小连续子数组长度为：" << result << endl;
}