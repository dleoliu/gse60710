#include <iostream>
#include <random>

using namespace std;

int main()
{
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(0, 9);
    uniform_int_distribution<char> Alphabet('A', 'Z');
    uniform_int_distribution<char> alphabet('a', 'z');
    uniform_int_distribution<int> selector(0, 9999);  // 乱数セレクター：大きな乱数を生成
    int length;

    cout << "Please input the length(>=20) of your new password:";
    cin >> length;

    while (true)
    {
        if (length < 20 )  // 桁数が20より少ない場合，エラーメッセージを表示．
        {
            cout << "\033[31m\033[1mYour password should longer than 20 characters. \033[m" << endl;
            cout << "Please input the length(>=20) of your new password:";
            cin >> length;
        }
        else if (length >= 50)  // 桁数が50より多い場合，エラーメッセージを表示．
        {
            cout << "\033[36m\033[1mIt's toooooooo long. \033[m" << endl;
            cout << "Please input the length(>=20) of your new password:";
            cin >> length;
        }
        else
        {
            cout << "\nYour new password is ";
            for (int i = 0; i < length; ++i)
            {
                if (selector(rng) % 2 == 0)  // 乱数セレクターに生成される数字が偶数の場合，パスワードにランダムに数字一つを入れる．
                {
                    cout << dist(rng);
                }
                else  // 生成された数字が奇数の場合，アルファベットを入れる．
                {
                    if (selector(rng) % 3 == 0)  // 乱数セレクターに生成された数字が3の倍数の場合，ランダムにアルファベットの小文字を入れる．
                    {
                        cout << alphabet(rng);
                    }
                    else  // ３の倍数ではない場合，ランダムにアルファベットの大文字を入れる．
                    {
                        cout << Alphabet(rng);
                    }
                }
            }
            cout << endl;
            cout << endl;
            break;
        }
    }
}
