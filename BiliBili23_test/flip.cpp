#include <iostream>
#include <vector>

using namespace std;

bool canTransorm(const vector<int>& a, const vector<int>&b, int left, int right)
{
    // 提前检查翻转区间的值是否可以匹配
    for (int i = left, j = right; i <= right; i++, j--)
    {
        if (a[i] != b[j])
        {
            return false;
        }
    }
    
    // 检查翻转区间外的值是否匹配
    for (int i = 0; i < left; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        } 
    }
    for (int i = right + 1; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    // 遍历所有可能的区间
    int count = 0;
    for (int left = 0; left < n; left++)
    {
        for (int right = left; right < n; right++)
        {
            if (canTransorm(a, b, left, right))
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
