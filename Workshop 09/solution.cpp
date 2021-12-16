#include <iostream>
#include <vector>
#include <random>

using namespace std;

random_device seed_gen;
default_random_engine engine(seed_gen());

uniform_real_distribution<double> randomNumberGen(0.0, 100.0);
uniform_int_distribution<int> sizeGen(2, 15);

vector<double> randomNumbersGen()
{
    int size = sizeGen(engine);

    vector<double> randomNumbers;

    for (size_t i = 0; i < size; ++i)
    {
        randomNumbers.insert(randomNumbers.end(), randomNumberGen(engine));
    }

    return randomNumbers;
}

vector< vector<double> > randomMatrixGen()
{
    int rows = sizeGen(engine);
    int columns = sizeGen(engine);

    vector< vector<double> > matrix(rows, vector<double>(columns));

    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            matrix.at(i).at(j) = randomNumberGen(engine);
        }
    }

    return matrix;
}

double average(vector<double>& numbers)
{
    int sum = 0;

    for (double number : numbers)
    {
        sum += number;
    }

    return double(sum) / numbers.size();
}

vector<int> argmax(vector< vector<double> > matrix)
{
    double max = matrix[0][0];
    vector<int> answer = { 0, 0 };

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for(size_t j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] > max)
            {
                answer[0] = i;
                answer[1] = j;
            }
        }
    }

    return answer;
}

void showVector(vector<double> items)
{
    for (double item : items)
    {
        cout << item;
        if(item != items.back())
        {
            cout << ", ";
        }
    }
    cout << endl;
    cout << endl;
}

void showVector(vector< vector<double> > matrix)
{
    for (vector<double> row : matrix)
    {
        for (double item : row)
        {
            cout << item;
            if (item != row.back())
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<double> randomNumbers = randomNumbersGen();
    showVector(randomNumbers);
    cout << "Average = " << average(randomNumbers) << endl;
    cout << endl;

    vector< vector<double> > randomMatrix = randomMatrixGen();
    vector<int> result = argmax(randomMatrix);
    showVector(randomMatrix);
    cout << "Maximum item's index = { ";
    for (int item : result)
    {
        cout << item + 1;
        if (item != result.back())
        {
            cout << ", ";
        }
    }
    cout << " }" << endl;
}