#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/// @brief 先运行能留下电量多的任务，才能有余电运行其他任务

const int MAX_ELECTRIC_QUANTITY = 4800;

bool myComparison(const pair<int, int>& taskA, const pair<int, int>& taskB)
{
    return (taskA.second - taskA.first) < (taskB.second - taskB.first);
}

int main(int argc, char const *argv[])
{
    string str, tmp;
    vector<pair<int, int>> tasks;

    getline(cin, str);
    stringstream ss(str);
    while(getline(ss, tmp, ','))
    {
        int p = tmp.find(":");
        string expend = tmp.substr(0, p);
        string mini = tmp.substr(p + 1);
        tasks.push_back({stoi(expend), stoi(mini)});
    }

    // 差值从小到大排序
    sort(tasks.begin(), tasks.end(), myComparison);

    // 贪心：从电量剩余值最小（即不能被别的任务运行提供电量帮助）开始，依次攀爬式上升
    int result = 0;
    for (int i = 0; i < tasks.size(); ++i)
    {
        result = max(result + tasks[i].first, tasks[i].second);
    }

    result = result <= MAX_ELECTRIC_QUANTITY ? result : -1;
    cout << result << endl;

    return 0;
}
