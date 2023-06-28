#include <iostream>
#include <vector>

using namespace std;

/// leetcode 27
///@brief 给你一个数组 nums 和一个值 val，你需要原地O(1)移除所有数值等于 val 的元素，并返回移除后数组的新长度。
/// 相向双指针方法，基于元素顺序可以改变的题目描述改变了元素相对位置，确保了移动最少元素
/// 时间复杂度O(n) 空间复杂度O(1)
class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (leftIndex <= rightIndex) {
            // 找左边等于val的元素
            while (leftIndex <= rightIndex && nums[leftIndex] != val){
                ++leftIndex;
            }
            // 找右边不等于val的元素
            while (leftIndex <= rightIndex && nums[rightIndex] == val) {
                -- rightIndex;
            }
            // 将右边不等于val的元素覆盖左边等于val的元素
            if (leftIndex < rightIndex) {
                nums[leftIndex++] = nums[rightIndex--];
            }
        }
        return leftIndex;   // leftIndex一定指向了最终数组末尾的下一个元素
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