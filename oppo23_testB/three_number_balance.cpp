#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::max;
using std::min;

class Solution
{
public:
    int getMinOp(int left, int right, int target)
    {
        if ((left + right) % 2) return std::numeric_limits<int>::max();
        int avg = (left + right) / 2;
        int count = 0;
        if (avg == target) return 0;
        else if (avg > target)
        {
            while (avg > target)
            {
                target++;
                count++;
            }
        }
        else
        {
            while (avg < target)
            {
                target--;
                count++;
            }
        }
        return count;
    }

    int threeNumberBalance(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        int result_A = getMinOp(nums[0], nums[2], nums[1]);
        if (result_A != std::numeric_limits<int>::max()) return result_A;
        return std::min(getMinOp(nums[0], nums[1], nums[2]), 
                            getMinOp(nums[1], nums[2], nums[0]));
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    Solution s;
    int result = s.threeNumberBalance(nums);
    cout << result << endl;
    return 0;
}
