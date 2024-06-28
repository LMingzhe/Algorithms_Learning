#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "helloworld";
    string sub = s.substr(0, 0);
    cout << sub << endl;
    return 0;
}