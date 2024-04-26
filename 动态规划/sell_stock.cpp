#include <iostream>
#include <vector>
#include <limits>
#include<algorithm>

using std::vector;
using std::min;
using std::max;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        
    }
};

// 贪心做法 时间复杂度:O(n) 空间复杂度:O(1)
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int low = INT32_MAX;
        int result = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            low = min(low, prices[i]);
            result = max(result, prices[i] - low);
        }
        return result;
    }
};