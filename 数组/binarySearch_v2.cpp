#include <iostream>
#include <vector>

using namespace std;

/// leetcode 704
///@brief 二分查找，左闭右开区间[)
/// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
///
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
            int middle = left + ((right - left) >> 1);
            cout << "本次middle值:" << middle << endl;
            if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] > target) {
                right = middle;
            } else {
                return middle;
            }
        }
        // 未找到目标
        return -1;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    int target = 5;
    int result = s.search(nums, target);
    if (result != -1) {
        cout << "找到了" << target << ", " << "它在数据的下标为" << result << endl;
    } else {
        cout << target << "不在数组中" << endl;
    }
    return 0;
}