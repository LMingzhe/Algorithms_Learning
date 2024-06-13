#include <iostream>
#include <vector>

using namespace std;

/// @brief 简单逻辑题，注意使用long long类型，使用int会溢出

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums[i] = num;
    }
    int x, y;
    cin >> x >> y;
    // x y 相邻且在 0 1 位置
    if ((nums[0] == x || nums[0] == y) && (nums[1] == x || nums[1] == y))
    {
        cout << "Yes" << endl;
        return 0;
    }
    // x y 在数组中其他位置相邻
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == x && (nums[i - 1] == y || nums[i + 1] == y))
        {
            cout << "Yes" << endl;
            return 0;
        }
        else if (nums[i] == y && (nums[i - 1] == x || nums[i + 1] == y))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}