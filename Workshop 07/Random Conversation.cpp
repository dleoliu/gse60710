#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

int main()
{
    // 会話のネタ
    vector<string> items = { "スイカキャンディー", "スイカアイス", "スイカジュース", "スイカの皮", "スイカ", "パスモ" };
    vector<int> prices = { 50, 150, 100, 20, 1000, 1500 };
    vector<string> descriptions = { 
        "甘いよ．",
        "冷たいよ．",
        "おいしいよ．",
        "何に使うんだろう．",
        "電車に乗れるよ．",
        "地下鉄通学券を買えるよ．"
    };

    // ランダムの種
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> pricesNumber(0, prices.size() - 1);
    uniform_int_distribution<int> descriptionsNumber(0, descriptions.size() - 1);
    uniform_int_distribution<int> luckyItem(0, 99999);
    uniform_int_distribution<int> luckyBit(0, 1);

    // 入力数値
    size_t n;

    cout << "名産品" << endl;
    for (size_t i = 0; i < items.size(); ++i)
    {
        cout << i << " : " << items[i] << endl;
    }
    cout << endl;

    cout << "何番のアイテムがいいかい？" << endl;
    cin >> n;
    cout << "\033[36m\033[1m\nしかし，耳が遠いおばあちゃんがこう聞こえた．．．\033[m\n" << endl;

    // ランダムに0~5から数値を取り出す．
    size_t wrongN = luckyItem(rng) % n + luckyBit(rng);

    cout << "はい〜" << wrongN << "番だね〜" << endl;
    
    // ランダムに値段と説明を取り出す．
    cout << items[wrongN] << "は" << prices[pricesNumber(rng)] << "円で，" << descriptions[descriptionsNumber(rng)] << endl;
}