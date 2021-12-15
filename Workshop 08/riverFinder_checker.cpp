#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main()
{
    // 変数の準備
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> mapGen(0, 4);
    uniform_int_distribution<int> mapSizeGen(1, 50);

    int mapSizeRow = 15;
    int mapSizeColumn = 15;
    int numberOfR = 0;  // 川の数

    vector<char> icons = { 'W', 'M', 'R', 'B', 'G' };
    vector< vector<int> > tileList(mapSizeRow, vector<int>(mapSizeColumn));
    vector< vector<int> > detectionSignal(mapSizeRow, vector<int>(mapSizeColumn));
    vector< vector<int> > storage;

    // 地図を生成
    for (size_t i = 0; i < mapSizeRow; ++i)
    {
        for (size_t j = 0; j < mapSizeColumn; ++j)
        {
            tileList.at(i).at(j) = mapGen(rng);
            detectionSignal.at(i).at(j) = 0;
        }
    }

    // 地図を表示
    for (vector<int> tiles : tileList)
    {
        for (int tile : tiles)
        {
            if (tile == 2)
            {
                cout << "\033[36m\033[1m" << icons[tile] << "\033[m";
            }
            else
            {
                cout << icons[tile];
            }
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

    // 川の数を数え上げる．複数ある連続のＲを一つの川と見なす．
    for (int i = 0; i < mapSizeRow; ++i)
    {
        for (int j = 0; j < mapSizeColumn; ++j)
        {
            if (tileList[i][j] == 2 && detectionSignal[i][j] == 0)
            {
                detectionSignal[i][j] = 1;
                ++numberOfR;
                storage.insert(storage.end(), { i, j });
                while (true)
                {
                    int temp_i = storage[storage.size() - 1][0];
                    int temp_j = storage[storage.size() - 1][1];
                    storage.pop_back();

                    if (temp_i - 1 >= 0)
                    {
                        if (tileList[temp_i - 1][temp_j] == 2 && detectionSignal[temp_i - 1][temp_j] == 0)
                        {
                            detectionSignal[temp_i - 1][temp_j] += 1;
                            storage.insert(storage.end(), { temp_i - 1, temp_j });
                        }
                    }
                    if (temp_j - 1 >= 0)
                    {
                        if (tileList[temp_i][temp_j - 1] == 2 && detectionSignal[temp_i][temp_j - 1] == 0)
                        {
                            detectionSignal[temp_i][temp_j - 1] += 1;
                            storage.insert(storage.end(), { temp_i, temp_j - 1 });
                        }
                    }
                    if (temp_i + 1 < mapSizeRow)
                    {
                        if (tileList[temp_i + 1][temp_j] == 2 && detectionSignal[temp_i + 1][temp_j] == 0)
                        {
                            detectionSignal[temp_i + 1][temp_j] += 1;
                            storage.insert(storage.end(), { temp_i + 1, temp_j });
                        }
                    }
                    if (temp_j + 1 < mapSizeColumn)
                    {
                        if (tileList[temp_i][temp_j + 1] == 2 && detectionSignal[temp_i][temp_j + 1] == 0)
                        {
                            detectionSignal[temp_i][temp_j + 1] += 1;
                            storage.insert(storage.end(), { temp_i, temp_j + 1 });
                        }
                    }

                    if (storage.size() == 0)
                    {
                        storage.clear();
                        break;
                    }
                }
            }
            else
            {
                continue;
            }
            
        }
    }
    cout << "川は" << numberOfR << "本ある．" << endl;
    
    cout << endl;
    for (vector<int> signals : detectionSignal)
    {
        for (int signal : signals)
        {
            if (signal == 1)
            {
                cout << "\033[36m\033[1m" << signal << "\033[m";
            }
            else if (signal > 1)
            {
                cout << "\033[31m\033[1m" << signal << "\033[m";
            }
            else
            {
                cout << signal;
            }
        }
        cout << endl;
    }
}