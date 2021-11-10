#include <iostream>

int main()
{
    using namespace std;

    int temp;

    cout << "Please input your number." << endl;
    cin >> temp;

    if (temp == 1)
    {
        cout << "(^^)H" << endl;
    }
    else if (temp == 2)
    {
        cout << "（＾Ｏ＾☆♪" << endl;
    }
    else if (temp == 3)
    {
        cout << "（；＿；）" << endl;
    }
    else if (temp == 99)  // 
    {
        cout << "~(・・？））" << endl;
    }
    else
    {
        cout << "それ以外の数が入力された場合は、何もしなくて良いです。" << endl;
    }
}