#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/// leetcode 150
/// @brief 逆波兰式求解
/// 时间复杂度：O(n)  空间复杂度：O(n)

class Solution
{
public:
    int evalRPN(std::vector<std::string>& tokens)
    {
        std::stack<long long> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            }
            else
            {
                st.push(std::stoll(tokens[i]));
            }
        }
        int result = st.top();
        st.pop();
        return result;
    }
};