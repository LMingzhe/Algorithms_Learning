#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> m_attack(5);
    vector<int> m_blood(5);
    vector<int> enemy_attack(5);
    vector<int> enemy_blood(5);
    for (int i = 5; i >= 1; i--)
    {
        cin >> m_attack[i - 1];
    }
    for (int i = 5; i >= 1; i--)
    {
        cin >> m_blood[i - 1];
    }
    for (int i = 5; i >= 1; i--)
    {
        cin >> enemy_attack[i - 1];
    }
    for (int i = 5; i >= 1; i--)
    {
        cin >> enemy_blood[i - 1];
    }
    while (!m_blood.empty() && !enemy_blood.empty())
    {
        int m_hero_attck = m_attack.back();
        int enemy_hero_blood = enemy_blood.back();
        enemy_blood.pop_back();
        if (enemy_hero_blood - m_hero_attck > 0)
        {
            enemy_blood.push_back(enemy_hero_blood - m_hero_attck);
        } else {
            enemy_attack.pop_back();
        }

        if (!enemy_blood.empty())
        {
            int enemy_hero_attck = enemy_attack.back();
            int m_hero_blood = m_blood.back();
            m_blood.pop_back();
            if (m_hero_blood - enemy_hero_attck > 0)
            {
                m_blood.push_back(m_hero_blood - enemy_hero_attck);
            } else {
                m_attack.pop_back();
            }
        }
    }

    if (enemy_blood.empty())
    {
        cout << "win" << endl;
        cout << m_blood.size() << endl;
    } else {
        cout << "lose" << endl;
        cout << enemy_blood.size() << endl;
    }

    return 0;
}
