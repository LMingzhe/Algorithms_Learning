#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

/// @brief 模拟过程即可

// 四舍五入保留N位小数
double roundToNDecimals(double number, int decimals)
{
    double factor = pow(10, decimals);
    return round(number * factor) / factor;
}

int main(int argc, char const *argv[])
{
    int freq;
    string data;
    unordered_map<int, int> umap;
    vector<int> freq_vec;

    cin >> freq;
    cin.ignore();
    getline(cin, data);
    stringstream ss(data);
    string tmp;
    while (getline(ss, tmp, ' '))
    {
        int p = tmp.find(":");
        string freq = tmp.substr(0, p);
        string loss = tmp.substr(p + 1);
        freq_vec.push_back(stoi(freq));
        umap[stoi(freq)] = stoi(loss);
    }
    
    int mindiff = INT_MAX;
    for (const auto& cur : freq_vec)
    {
        mindiff = min(mindiff, abs(freq - cur));
    }

    double result = 0.0;
    int cnt = 0;
    if (umap.find(freq + mindiff) != umap.end())
    {
        result += (double)umap[freq + mindiff];
        ++cnt;
    }
    if (umap.find(freq - mindiff) != umap.end())
    {
        result += (double)umap[freq - mindiff];
        ++cnt;
    }

    if (cnt == 2)
    {
        result /= 2.0;
        result = roundToNDecimals(result, 1);
    }

    // note std::cout 默认使用最小精度输出，这里还是用printf好
    printf("%.1f\n", result);

    return 0;
}
