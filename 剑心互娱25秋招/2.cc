#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param m int整型 水池容量
     * @param t int整型 总时长
     * @param m1 int整型 进水阀打开时每分钟进水量
     * @param t1 int整型 进水阀开关切换时长
     * @param m2 int整型 排水阀打开时每分钟排水量
     * @param t2 int整型 排水阀开关切换时长
     * @return int整型
     */
    int ComputeRemanentWater(int m, int t, int m1, int t1, int m2, int t2) 
    {
        int result = 0;

        bool flagin = true;
        bool flagout = true;
        int cntin = 0;
        int cntout = 0;

        for (int i = 1; i <= t; ++i)
        {
            if (cntin == 0)
            {
                flagin = true;
            }

            if (cntout == 0)
            {
                flagout = true;
            }
            
            if (flagin && flagout)
            {
                result += m1 - m2;
                result = max(0, result);
                result = min(m, result);
            } else if (flagin) {
                result += m1;
                result = min(result, m);
                --cntout;
            } else if (flagout) {
                result -= m2;
                result = max(0, result);
                --cntin;
            }

            if (i % t1 == 0 && flagin)
            {
                flagin = false;
                cntin = t1;
            }
            if (i % t2 == 0 && flagout)
            {
                flagout = false;
                cntout = t2;
            }

        }

        return result;
    }
};