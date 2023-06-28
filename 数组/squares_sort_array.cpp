#include <iostream>
#include <vector>

using namespace std;

/// leetcode 977 有序数组的平方
///@brief 给你一个按非递减顺序排序的整数数组 nums，返回每个数字的平方组成的新数组，要求也按非递减顺序 排序。
/// 时间复杂度 O(n)
///

class Solution {
public:
    vector<int> sortedSquares(vector<int> &A) {
        vector<int> result(A.size(), 0);
        int k = A.size() - 1;
        for (int i = 0, j = A.size() - 1; i <= j;) {
            if (A[i] * A[i] < A[j] * A[j]) {
                result[k--] = A[j] * A[j];
                j--;
            } else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> result;
    vector<int> nums{-7, -3, 2, 3, 11};
    cout << "原数组:";
    for (auto it = nums.begin(); it != nums.end(); it++) {
        if (it == nums.end() - 1) {
            cout << *it << endl;
        } else {
            cout << *it << ", ";
        }
    }
    result = s.sortedSquares(nums);
    cout << "平方后排序结果:";
    for (auto it = result.begin(); it != result.end(); it++) {
        if (it == result.end() - 1) {
            cout << *it << endl;
        } else {
            cout << *it << ", ";
        }
    }
    return 0;
}