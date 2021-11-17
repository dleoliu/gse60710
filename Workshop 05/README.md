# Workshop 05

Cで学ぶプログラミングの基礎の56ページ「おまけプログラム：とても長い蛇」をもとに改造。このコードをもとに、何か繰り返しアスキーアート（テキストのみで描く絵）を描いてみてください。繰り返しの回数や描画間隔も指定できるようにしても面白いでしょう。

1. 繰り返し何かを描ける
2. 繰り返し回数と間隔を指定できる
3. その他、何か発展的な内容がある

```
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
		cout << " I X X I \n";		
		cout << "IX X XI \n";
		cout << "I X X I \n";		
		cout << " IX X XI \n";
		cout << "   I X X I \n";		
		cout << "     IX X XI \n";
		cout << "      I X X I \n";		
		cout << "      IX X XI \n";
		cout << "     I X X I \n";
		std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
	}
}
```
