#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

// Возведение в степень
double power(double a, long n)
{
    double p = 1.0;
    for (int j = 0; j < n; j++)
    {
        p *= a;
    }
    return p;
}

// Возведение в степень logN + N/2 = O(N)
double powerB(double a, long n)
{
    if (n == 0) return 1.0;
    if (n == 1) return a;
    if (n % 2 == 0)
    {
        double x = powerB(a, n / 2);
        return x * x;
    }
    else
    {
        return a * powerB(a, n - 1);
    }
}

// Число Фибонначи через Золотое Сечение
int Fib(double n)
{
    double sqrtFive = sqrt(5);
    double phi = (1 + sqrtFive) / 2;
    return power(phi, n) / sqrtFive + 0.5;
}


// Умножение двух матриц
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Возведение матрицы A в степень n
vector<vector<int>> powerMatrix(const vector<vector<int>>& A, long n) {
    if (n == 0) {
        int size = A.size();
        vector<vector<int>> identity(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            identity[i][i] = 1;
        }
        return identity; // Возвращаем единичную матрицу при степени 0
    }
    if (n == 1) {
        return A; // Возвращаем исходную матрицу при степени 1
    }
    if (n % 2 == 0) {
        vector<vector<int>> halfPower = powerMatrix(A, n / 2);
        return multiplyMatrices(halfPower, halfPower);
    } else {
        vector<vector<int>> halfPower = powerMatrix(A, (n - 1) / 2);
        vector<vector<int>> result = multiplyMatrices(halfPower, halfPower);
        return multiplyMatrices(result, A);
    }
}

int main() {


    double res1 = power(2, 10);
    double res2 = powerB(2, 10);

    cout << "Power " << res1 << endl;
    cout << "PowerB " << res2 << endl;

    vector<vector<int>> matrix = {{1, 1}, {1, 0}};
    long n = 10;
    long N = n - 1;

    int result1 = Fib(n);

    vector<vector<int>> result2 = powerMatrix(matrix, N);

    int Fib = result2[0][0];

    cout << "Fib " << n << " Fibb number: " << result1 << endl;
    cout << "FibMatrice " << n << " Fibb number: " << Fib << endl;

    return 0;
}
