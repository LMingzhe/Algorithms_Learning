#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void subArray(vector<int>& array, int x)
{
    // dp[i][0]:
    // dp[i][1]:
    vector<vector<int>> dp(array.size(), vector<int>(2));

}

int main(int argc, char** argv)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> array(n);
        while(n--)
        {
            int num;
            cin >> num;
            array.push_back(num);
        }
        subArray(array, x);
    }
    return 0;
}
