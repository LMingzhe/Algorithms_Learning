#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/// leetcode 399 除法求值
/// @brief 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
///        另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。
///        返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。
/// 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
/// 注意：未在等式列表中出现的变量是未定义的，因此无法确定它们的答案。

// 并查集 时间复杂度O((N+Q)logA) 空间复杂度O(A)
//       N：输入方程 equations 的长度 Q：为查询数组 queries 的长度 A：equations 里不同字符的个数
class Solution
{
private:
    unordered_map<string, string> parent;
    unordered_map<string, double> weightMap;

    // 并查集模板
    // 并查集初始化
    void init() 
    {
        // 本题无需初始化
    }

    // 并查集寻根过程，每次查找x的根节点都使用这个函数，因为要进行路径压缩，不要用 parent[x]。
    string find(string& x)
    {
        if (parent[x] == x) return x;
        //note：路径压缩
        string parentX = parent[x];
        parent[x] = find(parent[x]);
        weightMap[x] = weightMap[x] * weightMap[parentX];
        return parent[x];
    }

    // 判断x、y是否找到同一个根（是否为同一集合）
    bool isSame(string& x, string& y)
    {
        return find(x) == find(y);
    }

    // 将 x->y 这条边加入并查集
    void join(string&x, string& y, double& weight)
    {
        // 这部分代码与 calcEquation() 函数中 for 循环中的代码一致
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                    vector<vector<string>>& queries)
    {
        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            // 构建并查集图，分子为 x，分母为 y  x->y
            string x = equations[i][0], y = equations[i][1];
            double weight = values[i];
            if (!parent.count(x) && !parent.count(y)) // 情况一：x y 都不在并查集内，构建一个新的集合
            {
                parent[x] = y;
                parent[y] = y;
                weightMap[x] = weight;
                weightMap[y] = 1.0;
            } else if (!parent.count(x)) { // 情况二：x不在并查集内，直接连接 x->y 即可
                parent[x] = y;
                weightMap[x] = weight;
            } else if (!parent.count(y)) { // 情况三：y不在并查集内，初始化y作为x的新根节点
                parent[y] = y;
                weightMap[y] = 1.0;
                string parentX = find(x); //note：注意这里需要使用find()寻找根节点，因为需要的是路径压缩后的根节点
                parent[parentX] = y; // 更新 y 作为 parentX 新的根节点
                weightMap[parentX] = weight / weightMap[x]; // 更新 parentX 的权值
                //note：这里可以不更新 x 的根节点和权值，因为下一次使用 find(x) 会自动更新
            } else { // 情况四：x、y都在并查集内
                // find() 分别寻找x、y的根节点（路径压缩后的）
                string parentX = find(x);
                string parentY = find(y);
                // 属于同一个集合，跳过
                if (parentX == parentY) continue; 
                // 不属于同一个集合，更新x的根节点 parentX 的根节点为y的根节点 parentY
                parent[parentX] = parentY;
                weightMap[parentX] = weight * weightMap[y] / weightMap[x]; // 更新x根节点 parentX 的权值
                // 同理，这里可以不更新 x 的根节点和权值信息，等下一次 find(x) 时自动更新
            }
        }
        vector<double> result;
        for (const auto& query : queries)
        {
            string x = query[0], y = query[1];
            if (!parent.count(x) || !parent.count(y))
            {
                // x or y 不在并查集内
                result.push_back(-1.0);
            } else {
                if (isSame(x, y))
                {
                    result.push_back(weightMap[x] / weightMap[y]);
                } else {
                    // x、y在并查集内，但不属于同一个集合
                    result.push_back(-1.0);
                }
            }
        }
        return result;
    }
};