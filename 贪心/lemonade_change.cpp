#include <iostream>
#include <vector>

using std::vector;

/// leetcode 860 柠檬水找零
/// @brief 每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
///        每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
///        如果你能给每位顾客正确找零，返回 true ，否则返回 false 。注意，一开始你手头没有任何零钱。
///  时间复杂度：O(n) 空间复杂度：O(1)

class Solution
{
public:
    bool lemonadeChange(vector<int>& bills)
    {
        if (bills[0] != 5) return false; // 第一笔不是5美元，就无法找零
        int count5 = 1;  // 默认第一笔是给了5美元
        int count10 = 0;
        int count20 = 0;
        for (int i = 1; i < bills.size(); i++) // 从第二笔订单开始
        {
            if (bills[i] == 5)
            {
                count5++;
            }
            else if (bills[i] == 10)
            {
                if (count5 == 0) return false;
                count5--;
                count10++;
            }
            else
            {
                if (count10 > 0 && count5 > 0)  // 优先使用10美元，因为5美元用处更大
                {
                    count10--;
                    count5--;
                    count20++;
                }
                else if (count5 >= 3)
                {
                    count5 -= 3;
                    count20++;
                }
                else
                {
                    return false;       
                } 
            }
        }
        return true;
    }
};