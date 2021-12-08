# Workshop 08

1. マップを完成させよう。壁のある場所、見張りのいる場所、川、橋などを文字で表現しよう。
2. 地図情報から見張りの人数を数えるようなプログラムを作ろう。
3. 地図情報から黄金スイカのある場所が何行何列なのか表示するプログラムを作ろう。ただし、0行0列から数えることとする。
4. そのほか、新たな取り組みを考えてみよう。

```C++
#include <iostream>
#include <vector>
int main()
{
    // 地図の情報
    std::vector<std::vector<int>> tileList =
    {
    記載せよ
    };
    // 地図に使う記号（char型で表現できる文字）
    std::vector<char> icons = { 記載せよ };
    for (std::vector<int> tiles : tileList)
    {
        for (int tile : tiles)
        {
            std::cout << icons[tile];
        }
        std::cout << '\n';
    }
    // 地図記号の説明
    std::cout << '\n';
    std::cout << icons[1] << ": 壁\n";
    std::cout << icons[2] << ": 黄金のスイカの位置\n";
    std::cout << icons[3] << ": 見張りが立っている位置\n";
}
```