#include <iostream>
#include "test.h"
using namespace std;
int main(int argc, char **argv) {

    int i = 42;
    const int &r1 = i;

    cout << r1 << endl;

    i = 66;
    cout << r1 << endl;
    return 0;
}