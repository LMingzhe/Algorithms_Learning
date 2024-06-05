#include <iostream>
#include <vector>

using std::vector;
using std::swap;

/// leetcode 数组中的第k个最大元素
/// @brief 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
///        请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
///        你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

// 基于快速排序的选择方法 时间复杂度O(n) 空间复杂度O(logn)
class Solution
{
public:
    int quickSelect(vector<int>& nums, int left, int right, int target)
    {
        if (left >= right)
        {
            return nums[target];
        }
        int i = left, j = right;
        int pivot = left;
        while (i < j)
        {
            while (nums[j] > nums[pivot] && i < j) j--;
            while (nums[i] <= nums[pivot] && i < j) i++;
            if (i < j) swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[pivot]);
        if (i == target) return nums[i];
        else if (target < i) return quickSelect(nums, left, i - 1, target);
        else return quickSelect(nums, i + 1, right, target);
    }
    int findKthLargest(vector<int>& nums, int k)
    {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }
};

// 基于堆排序的选择方法 时间复杂度O(nlogn) 建堆时间为O(n) 删除的总代价O(klogn) 空间复杂度O(logn)
class Solution
{
public:
    // 调整以i为根节点的堆
    void maxHeapify(vector<int>& a, int i, int heapSize)
    {
        int l = i * 2 + 1; // 左节点
        int r = i * 2 + 2; // 右节点
        int largest = i;   // 存储当前子树（三个节点）最大节点索引
        if (l < heapSize && a[l] > a[largest]) largest = i;
        if (r < heapSize && a[r] > a[largest]) largest = r;
        if (largest != i)
        {
            swap(a[largest], a[i]);
            // 上面调整完的结果可能会影响下面已调整的结果，需要递归向下重新调整
            maxHeapify(a, largest, heapSize);
        }
    }
    // 建堆，这里使用数组模拟树，从数组二分之一处开始调整建堆即可保证成功建堆
    void buildMaxHeap(vector<int>& a, int heapSize)
    {
        for (int i = heapSize / 2; i >= 0; i--)
        {
            maxHeapify(a, i, heapSize);
        }
    }
    int findKthLargest(vector<int>& nums, int k)
    {
        int heapSize = nums.size(); // 堆大小
        buildMaxHeap(nums, heapSize); // 建堆
        // 求第k个最大值，只需置换k-1次，nums[0]（堆顶）即为所求值
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; i--)
        {
            swap(nums[0], nums[i]);
            // note 逻辑上的删除，置换后堆大小需要-1
            --heapSize; 
            maxHeapify(nums, 0, heapSize); // 重新调整堆
        }
        return nums[0];
    }
};