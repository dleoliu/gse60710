# Workshop 06

1. 乱数 n の値を表示しましょう。
2. その乱数をもとに様々な処理をしましょう。

```C++
#include <iostream>
#include <random>
int main()
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 9);
    int n = dist(rng);
}
```
