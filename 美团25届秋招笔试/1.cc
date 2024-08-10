#include <iostream>

using namespace std;

void isOs(int& x)
{
    if (x % 2 == 0)
    {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        isOs(x);
    }
    return 0;
}