#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
    unordered_map<string, vector<int>> map;
    map["up"] = {-1, 0};
    map["below"] = {1, 0};
    map["left"] = {0, -1};
    map["right"] = {0, 1};
    cout << " test.cpp " << endl;
    return 0;
}
