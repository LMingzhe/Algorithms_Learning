#include <iostream>
#include <vector>

using namespace std;

/// eetcode 704
///@brief 二分查找，左闭右闭区间[]
/// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
///
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + ((right - left) / 2); // 防止溢出 等同于(lef + right) / 2
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        // 未找到目标值
        return -1;
    }
};

int main (int argc, char **argv) {
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