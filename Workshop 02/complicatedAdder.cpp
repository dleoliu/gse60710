#include <iostream>
int main()
{
    using namespace std;

    int temp, sum = 0;

    cout << "Please input 4 integers." << endl;
    cout << "a: "; cin >> temp; sum += temp;
    cout << "b: "; cin >> temp; sum += temp;
    cout << "c: "; cin >> temp; sum += temp;
    cout << "d: "; cin >> temp; sum += temp;
    
    cout << "The sum is " << sum << "." << endl;
}