#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a = 3;

    int c = a++;
    int b = ++a;
    cout << c << endl;
    cout << b << endl;
    return 0;
}
