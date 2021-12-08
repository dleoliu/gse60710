#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main()
{
    // 変数の準備
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> mapGen(0, 4);
    uniform_int_distribution<int> mapSizeGen(1, 99);

    int mapSizeRow = mapSizeGen(rng);
    int mapSizeColumn = mapSizeGen(rng);
    int numberOfM = 0;  // 見張りの人数

    vector<char> icons = { 'W', 'M', 'R', 'B', 'G' };
    vector< vector<int> > tileList(mapSizeRow, vector<int>(mapSizeColumn));

    // 地図を生成
    for (size_t i = 0; i < mapSizeRow; ++i)
    {
        for (size_t j = 0; j < mapSizeColumn; ++j)
        {
            tileList.at(i).at(j) = mapGen(rng);
        }
    }

    // 地図を表示
    for (vector<int> tiles : tileList)
    {
        for (int tile : tiles)
        {
            cout << icons[tile];
        }
        cout << '\n';
    }

    cout << '\n';
    cout << icons[0] << ": 壁\n";
    cout << icons[1] << ": 見張りが立っている位置\n";
    cout << icons[2] << ": 川の位置\n";
    cout << icons[3] << ": 橋の位置\n";
    cout << icons[4] << ": 黄金のSuicaの位置\n";
    cout << endl;

    // 見張りを数え上げながら黄金の位置を表示
    for (size_t i = 0; i < mapSizeRow; ++i)
    {
        for (size_t j = 0; j < mapSizeColumn; ++j)
        {
            if (icons[tileList[i][j]] == 'M')
            {
                ++numberOfM;
            }
            if (icons[tileList[i][j]] == 'G')
            {
                cout << i + 1 << "行" << j + 1 << "列に黄金Suicaがある．" << endl;
            }
        }
    }
    cout << "見張りは" << numberOfM << "人いる．" << endl;
}