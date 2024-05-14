#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::vector;
using std::unordered_map;
using std::cin;
using std::cout;
using std::endl;
using std::string;

/// @brief 纯逻辑题，理清楚过程即可求解
class Solution
{
public:
    int calculatedDamage(int roundNum, int basicAttack, int comboAttack, string evade)
    {
        int result = 0;
        int combo = 0; // 连击数，初始化为0
        int curAttack = basicAttack; // 初始化当前攻击力
        for (int i = 0; i < roundNum; i++)
        {
            result += curAttack; // 先攻击，所以伤害值先加上
            // 只要攻击完都算一次连击，更新连击数和攻击力
            combo++;
            curAttack = basicAttack + combo * comboAttack;
            if (evade[i] == 'x') // 后防守，没有成功闪避则攻击力和连击数更新为初始值
            {
                curAttack = basicAttack;
                combo = 0;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    int roundNum, basicAttack, comboAttack;
    string evade;
    cin >> roundNum >> basicAttack >> comboAttack;
    cin >> evade;
    Solution s;
    int result = s.calculatedDamage(roundNum, basicAttack, comboAttack, evade);
    cout << result << endl;
    return 0;
}
