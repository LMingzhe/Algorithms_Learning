#include <iostream>
#include <vector>

using namespace std;

/// @brief 依据题意，要使元素和最小，数组只能是 1k,2k,3k...nk
///        对数组求和，(1+2+3+...n)*k 对括号内数列求和即可

int main(int argc, char** argv)
{
    long n, k;
    cin >> n >> k;
    long long result = ((1 + n) * n * k) / 2;
    cout << result << endl;
    return 0;
}
