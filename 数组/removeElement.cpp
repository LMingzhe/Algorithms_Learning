#include <iostream>
#include <vector>

using namespace std;

/// leetcode 27
///@brief 给你一个数组 nums 和一个值 val，你需要原地O(1)移除所有数值等于 val 的元素，并返回移除后数组的新长度。
/// 双指针法（快慢指针法）： 通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。
///     快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
///     慢指针：指向更新 新数组下标的位置
/// 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    cout << "原数组为：";
    for (auto it = nums.begin(); it != nums.end(); it++) {
        if (it == nums.end() - 1) {
            cout << *it << endl;
        } else {
                  cout << *it << ", ";
        }
    }
    int result = s.removeElement(nums, val);
    cout << "移除元素值为：" << val << ", ";
    cout << "移除指定元素后的新数组长度为:" << result << endl;
    cout << "移除后有效数组数据为：";
    for (int i = 0; i < result; i++) {
        if (i == result - 1) {
            cout << nums[i] << endl;
        } else {
            cout << nums[i] << ", ";
        }
    }
    return 0;
}