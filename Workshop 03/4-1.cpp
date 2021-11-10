#include <iostream>

int main()
{
    using namespace std;

    int x, y;

    cout << "Please input x & y." << endl;
    cout << "x: "; cin >> x;
    cout << "y: "; cin >> y;

    if (y <= x)
    {
        cout << "x - y = " << x - y << endl;
    }
    else
    {
        cout << "minus ni narimasu" << endl;
    }
}