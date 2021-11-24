#include <iostream>
#include <random>

using namespace std;

int main()
{
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(0, 9);
    uniform_int_distribution<char> Alphabet('A', 'Z');
    uniform_int_distribution<char> alphabet('a', 'z');
    uniform_int_distribution<int> selector(0, 9999);
    int length;

    cout << "Please input the length(>=20) of your new password:";
    cin >> length;

    while (true)
    {
        if (length < 20 )
        {
            cout << "\033[31m\033[1mYour password should longer than 20 characters. \033[m" << endl;
            cout << "Please input the length(>=20) of your new password:";
            cin >> length;
        }
        else if (length >= 50)
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
                if (selector(rng) % 2 == 0)
                {
                    cout << dist(rng);
                } else {
                    if (selector(rng) % 3 == 0)
                    {
                        cout << alphabet(rng);
                    } else {
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