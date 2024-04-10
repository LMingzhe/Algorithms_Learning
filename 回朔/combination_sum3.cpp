#include <iostream>
#include <vector>

using std::vector;

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;

    void backtracking(int targetSum, int k, int sum, int startIndex)
    {
        if (sum > targetSum) // 剪枝
        {
            
            return;
        }

        if (path.size() == k)
        {
            if (sum == targetSum)
            {
                result.push_back(path);
            }
            return;
        }

        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)
        {
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        result.clear();
        path.clear();
        sum = 0;
        backtracking(n, k, sum, 0);
        return result;
    }
};