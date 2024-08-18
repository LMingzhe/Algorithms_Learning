#include <bits/stdc++.h>

using namespace std;

/// @brief AC 35.71

int main(int argc, char const *argv[])
{
    string N;
    cin >> N;
    string comand;
    cin >> comand;

    int cnt = 0;
    int index_N = 0;
    int index_comand = 0;

    while (index_N < N.length() && index_comand < comand.length())
    {
        if (N[index_N] == comand[index_comand])
        {
            ++cnt;
            ++index_N;
            ++index_comand;
            continue;
        } else if (comand[index_comand] == '*') {
            while (comand[index_comand - 1] == N[index_N])
            {
                ++cnt;
                ++index_N;
            }
            ++index_comand;
        } else {
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}
