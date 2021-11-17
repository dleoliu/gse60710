#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
int main() {
	int count = 3, interval_ms = 1000;
	cout << "      Y   \n";
	cout << "     _I_  \n";
	cout << "    /O  O\\ \n";
	cout << "   I     I \n";
	cout << "   I     I \n";
	for (int i=0; i < count; ++i)
	{
		cout << "   IX X XI \n";
		cout << " I X X I     /\n";		
		cout << "IX X XI ---->\n";
		cout << "I X X I      \\\n";		
		cout << " IX X XI \n";
		cout << "   I X X I \n";		
		cout << "     IX X XI \n";
		cout << "  \\   I X X I \n";		
		cout << "  <--- IX X XI \n";
		cout << "  /  I X X I \n";
		std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
	}
    cout << "    I X X I \n";
    cout << "   I X I \n";
    cout << "  I I \n";
    cout << " I \n";
}
