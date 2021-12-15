# Workshop 09

1. 3つの値の平均値を返す関数を作ろう
2. vectorの全要素の平均値を返す関数を作ろう
3. 最大値を取るインデックスを返す関数を作ろう
4. そのほか、新たな関数を考えてみよう。

```C++
#include <vector>

/// 3つの値 a, b, c の算術平均
double average(double a, double b, double c);

/// vectorの全要素の算術平均
double average(std::vector<double> v);

/// 最大値を取るインデックス{i行, j列}を返す。最大値が複数ある場合は、最初の行が最小のもの、同じ行なら列が最小のもの
std::vector<int> argmax(std::vector<std::vector<int>> matrix);

```