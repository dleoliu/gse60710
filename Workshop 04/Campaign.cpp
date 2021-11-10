#include <iostream>

int main()
{
    int monsterHP = 100, myHP = 100;
    for (;;)
    {
        std::cout << "プラスの行動 1: パンチ 2: 剣で攻撃 3: 回復薬 4: 魔法\n";
        int action;
        std::cin >> action;
        if (action == 1)
        {
            monsterHP -= 15;
            myHP -= 20;
        }
        else if (action == 2)
        {
            monsterHP -= 30;
            myHP -= 40;
        }
        else if (action == 3)
        {
            myHP += 30;
            if (myHP >= 100)
            {
                myHP = 100;
            }
        }
        else
        {
            monsterHP /= 2;
            myHP -= 45;
        }
        std::cout << "モンスター: " << monsterHP << "\n";
        if (monsterHP <= 0)
        {
            std::cout << "モンスターを倒した!\n";
            break;
        }
        std::cout << "プラス　　: " << myHP << "\n";
        if (myHP <= 0)
        {
            std::cout << "モンスターにやられてしまった!\n";
            break;
        }
    }
}