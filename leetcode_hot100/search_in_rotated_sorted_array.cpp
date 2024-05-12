#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) // 找到最大值
        {
            int mid = (i + j) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                if (nums[mid] == target) return mid;
                else if (target > nums[mid]) return -1;
                else
                {
                    if (target > nums[i])  j = mid;
                    else i = mid + 1;
                    break;
                }
            }
            if (nums[mid] < nums[i]) j = mid; // 最大值在左边部分
            else i = mid; // 最大值在右边部分
        }
        while (i < j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) j = mid;
            else if (nums[mid] < target) i = mid;
        }
        return -1;
    }
};