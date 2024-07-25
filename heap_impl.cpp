#include <iostream>
#include <queue>

using namespace std;

class HeapImpl
{
public:
    // 小顶推
    template<typename T>
    class myComparisonDown()
    {
    public:
        bool operator()(const T& lhs, const T& rhs)
        {
            return lhs > rhs;
        }
    };

    // 大顶堆
    template<typename T>
    class myComparisonUp()
    {
    public:
        bool operator()(const T& lhs, const T& rhs)
        {
            return lhs < rhs;
        }
    }

    // arg1：存储的元素类型 arg2：底层容器类型 arg3：优先级函数
    template<typename T, typename V>
    priority_queue<T, V, myComparisonDown> pri_Dque;
    // eg：priority_queue<pair<int, int>, vector<pair<int, int>>, myComparisonDown> pri_que;

    template<typename T, typename V>
    priority_queue<T, V, myComparisonUp> pri_Uque;
};