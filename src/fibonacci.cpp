#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/// @brief use recursion to calculate fibonacci number
/// @param n the index of fibonacci number
/// @return the fibonacci number
int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

vector<int> memo{1, 1};
/// @brief use memo to record the result of fibonacci number,the memo must be global variable
/// @param n the index of fibonacci number
/// @return the fibonacci number
int memoFib(int n)
{
    if (n <= memo.size())
    {
        return memo[n - 1];
    }
    int result = memoFib(n - 1) + memoFib(n - 2);
    memo.push_back(result);
    return result;
}

/// @brief use dynamic programming to calculate fibonacci number
/// @param n the index of fibonacci number
/// @return the fibonacci number
int DPFib(int n)
{
    vector<int> dp{1, 1};
    for (int i = 2; i < n; i++)
    {
        dp.push_back(dp[i - 1] + dp[i - 2]);
    }
    return dp[n - 1];
}

/// @brief use dynamic programming to calculate fibonacci number,but only use two variables to record the result
/// @param n the index of fibonacci number
/// @return the fibonacci number
int optimizedDPFib(int n)
{
    int prev = 1;
    int curr = 1;
    for (int i = 2; i < n; i++)
    {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return curr;
}

/// @brief quick power,calculate a^n
/// @param a the base of the power mat
/// @param n the exponent of the power mat
/// @return the result of a^n
auto quickPow(auto a, auto n)
{
    vector<int> numbers;
    while (n > 0)
    {
        numbers.push_back(n % 2);
        n /= 2;
    }
    double result = 1.0;
    for (int i = numbers.size() - 1; i >= 0; i--)
    {
        if (numbers[i] == 1)
            result = result * result * a;
        else
            result = result * result;
    }
    return result;
}

/// @brief use formula to calculate fibonacci number
/// @param n the index of fibonacci number
/// @return the fibonacci number
int formulaFib(int n)
{
    double arg1 = (1 + sqrt(5)) / 2;
    double arg2 = (1 - sqrt(5)) / 2;
    return round((quickPow(arg1, n) - quickPow(arg2, n)) / sqrt(5));
}

/// @brief this function is used to calculate the matrix multiplication
/// @param a the first matrix
/// @param b the second matrix
/// @return the result of matrix multiplication
auto multiply(auto a, auto b)
{
    vector<vector<int>> matrix;
    matrix.resize(2);
    for (int i = 0; i < 2; i++)
    {
        matrix[i].resize(2);
    }
    matrix[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    matrix[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    matrix[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    matrix[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    return matrix;
}

/// @brief this function is used to calculate the matrix power
/// @param a this is the matrix
/// @param n this is the exponent of the matrix
/// @return the result of matrix power
auto matrixQuickPow(auto a, int n)
{
    vector<int> numbers;
    while (n > 0)
    {
        numbers.push_back(n % 2);
        n /= 2;
    }
    vector<vector<int>> result{{1, 0}, {0, 1}};
    for (int i = numbers.size() - 1; i >= 0; i--)
    {
        if (numbers[i] == 1)
            result = multiply(multiply(result, result), a);
        else
            result = multiply(result, result);
    }
    return result;
}

/// @brief use matrix quick power to calculate fibonacci number
/// @param n the index of fibonacci number
/// @return the fibonacci number
int matrixFib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    vector<vector<int>> matrix{{0, 1}, {1, 1}};
    auto result = matrixQuickPow(matrix, n - 2);
    return result[0][1] + result[1][1];
}

int main()
{
    // 使用六种方法计算结果
    // 并且计算每次计算的时间
    // 递归
    auto start = clock();
    cout << fib(40) << endl;
    auto end = clock();
    cout << "递归计算耗时：" << (end - start) / 1000.0 << "ms" << endl;

    // 备忘录递归
    start = clock();
    cout << memoFib(40) << endl;
    end = clock();
    cout << "备忘录递归计算耗时：" << (end - start) / 1000.0 << "ms" << endl;

    // 动态规划
    start = clock();
    cout << DPFib(40) << endl;
    end = clock();
    cout << "动态规划计算耗时：" << (end - start) / 1000.0 << "ms" << endl;

    // 优化动态规划
    start = clock();
    cout << optimizedDPFib(40) << endl;
    end = clock();
    cout << "优化动态规划计算耗时：" << (end - start) / 1000.0 << "ms" << endl;

    // 通项公式法
    start = clock();
    cout << formulaFib(40) << endl;
    end = clock();
    cout << "通项公式法计算耗时：" << (end - start) / 1000.0 << "ms" << endl;

    // 矩阵快速幂
    start = clock();
    cout << matrixFib(40) << endl;
    end = clock();
    cout << "矩阵快速幂计算耗时：" << (end - start) / 1000.0 << "ms" << endl;
    return 0;
}