#include <iostream>
#include <string>

using namespace std;

/// @brief 注意cursorIndex不同位置的处理

void insert(string& str, int& cursorIndex, const string& substr)
{
    int sszie = substr.size();
    if (cursorIndex <= 0)
    {
        str = substr + str;
    } else if (cursorIndex >= str.size()) {
        str = str + substr;
    } else {
        str = str.substr(0, cursorIndex) + substr + str.substr(cursorIndex);
    }
    cursorIndex += sszie;
}

void move(string& str, int& cursorIndex, const int& cnt)
{
    if (cnt == 0 || cursorIndex + cnt < 0 || cursorIndex + cnt > str.size()) return;
    cursorIndex += cnt;
}

void deleteStr(string& str, int& cursorIndex, const int& len)
{
    if (len <= 0 || len > cursorIndex) return;
    if (cursorIndex >= str.size())
    {
        if (len == cursorIndex)
        {
            str = "";
            cursorIndex = 0;
        } else {
            str = str.substr(0, cursorIndex - len);
            cursorIndex -= len;
        }
    } else {
        if (len == cursorIndex)
        {
            str = str.substr(cursorIndex);
            cursorIndex = 0;
        } else {
            str = str.substr(0, cursorIndex - len) + str.substr(cursorIndex);
            cursorIndex -= len;
        }
    }
}

void copy(string& str, int& cursorIndex)
{
    if (cursorIndex <= 0)
    {
        return;
    } else if (cursorIndex >= str.size()) {
        str = str + str;
    } else {
        string subStr = str.substr(0, cursorIndex);
        str = subStr + subStr + str.substr(cursorIndex);
    }
}

void serializeStr(string& str, int& cursorIndex)
{
    if (cursorIndex == 0)
    {
        str = "|" + str;
    } else if (cursorIndex >= str.size()) {
        str = str + "|";
    } else {
        str = str.substr(0, cursorIndex) + "|" + str.substr(cursorIndex);
    }
}

int main(int argc, char const *argv[])
{
    string str = "";
    int cursorIndex = 0; // 游标位置索引，范围为 [0, str.size()]，在使用str操作时注意可能超出索引范围
    while (true)
    {
        string op;
        cin >> op;
        if (op == "end") break;
        if (op == "insert")
        {
            string substr;
            cin >> substr;
            insert(str, cursorIndex, substr);
        } else if (op == "move") {
            int cnt;
            cin >> cnt;
            move(str, cursorIndex, cnt);
        } else if (op == "delete") {
            int len;
            cin >> len;
            deleteStr(str, cursorIndex, len);
        } else if (op == "copy") {
            copy(str, cursorIndex);
        }
    }
    serializeStr(str, cursorIndex);
    cout << str << endl;
    return 0;
}
