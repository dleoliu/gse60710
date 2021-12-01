# Workshop 07

タイトルには、くじ引きプログラムなど、ランダムで何をするプログラムなのか簡潔に書いてください。

1. 合計の重さ、総数、平均の重さ、6kg以下のスイカの数、一番軽いスイカの重さ等を表示
2. 重さの標準偏差を表示
3. この例に限らず、`std::vectror<std::string>`と`for`文を使ったプログラム

```C++
#include <iostream>
#include <vector>
int main()
{
    // 収穫したスイカの重さ
    std::vector<double> weightList = { 6.4, 9.2, 8.6, 7.1, 8.5, 4.4, 6.9, 10.1 };
    double sum = 0.0;
    for (double weight : weightList)
    {
        sum += weight;
    }
    std::cout << "合計" << sum << "kg\n";
}
```
