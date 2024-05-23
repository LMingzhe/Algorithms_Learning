#include <iostream>
#include <vector>
#include <string>

using namespace std;

/// @brief 将每个数字转化为字符串，循环找到非'0'项即可
class Solution
{
public:
    int deleteNumber(vector<int>& nums)
    {
        int opCnt = 0;
        for (const auto& num : nums)
        {
            if (num == 0) continue; // 数字为0，跳过不同操作
            string num_str = to_string(num); // 转化为字符串
            for (const auto& ch : num_str)
            {
                if (ch != '0') opCnt++; // 只有非0数字需要删除，操作数+1
            }
        }
        return opCnt;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums;
    int input_cnt = 0;
    cin >> input_cnt;
    while (input_cnt--)
    {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    Solution s;
    int result = s.deleteNumber(nums);
    cout << result << endl;
    return 0;
}
