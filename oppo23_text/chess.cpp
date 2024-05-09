#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;
using std::max;
using std::min;

/// FIXME 有点复杂，第一感觉是动态规划，但是动态数组不好定义，任意数k也无法解决，后续看题解再补充答案

class Solution
{
public:
    int calculateStep(int x1, int x2, int y1, int y2)
    {
        if (x1 == x2 && y1 == y2) return 0;
        int size_x = x2 - x1;
        int size_y = y2 - y1;
        // dp数组
        vector<vector<int>> dp(size_x, vector<int>(size_y));

    }
};