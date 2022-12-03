#include <iostream>
#include <vector>
using namespace std;

/*一、定义二维向量实现矩阵的操作。要求：
1）在主函数定义两个二维向量，并赋值。
2）设计矩阵加，矩阵减，矩阵相乘三个函数。
3）在主函数调用上述三个函数，完成测试。
*/

int setMatrix(vector<vector<int>> &matrix)
{
    vector<int> vecTemp;
    for (int temp; cin >> temp;)
    {
        vecTemp.push_back(temp);
        if (cin.get() == '\n')
        {
            matrix.push_back(vecTemp);
            vecTemp.clear();
            if (cin.peek() == '\n')
                break;
        }
    }
    return 0;
}

int matrix_add(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2, vector<vector<int>> &matrix3)
{
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
    {
        cout << "矩阵不同，无法相加" << endl;
        return -1;
    }
    for (int i = 0; i < matrix1.size(); i++)
    {
        for (int j = 0; j < matrix1[0].size(); j++)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return 0;
}

int matrix_sub(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2, vector<vector<int>> &matrix3)
{
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
    {
        cout << "矩阵不同，无法相减" << endl;
        return -1;
    }
    for (int i = 0; i < matrix1.size(); i++)
    {
        for (int j = 0; j < matrix1[0].size(); j++)
        {
            matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return 0;
}

int matrix_mul(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2, vector<vector<int>> &matrix3)
{
    if (matrix1[0].size() != matrix2.size())
    {
        cout << "矩阵不同，无法相乘" << endl;
        return -1;
    }
    for (int i = 0; i < matrix1.size(); i++)
    {
        for (int j = 0; j < matrix2[0].size(); j++)
        {
            for (int k = 0; k < matrix1[0].size(); k++)
            {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return 0;
}

//将matrix3里面所有的元素都置为0
int matrixSetZero(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            matrix[i][j] = 0;
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;
    vector<vector<int>> matrix3;
    cout << "请输入矩阵1" << endl;
    setMatrix(matrix1);
    cout << "请输入矩阵2" << endl;
    setMatrix(matrix2);
    matrix3.resize(matrix1.size());
    for (int i = 0; i < matrix1.size(); i++)
    {
        matrix3[i].resize(matrix1[0].size());
    }
    cout << "矩阵1" << endl;
    for (int i = 0; i < matrix1.size(); i++)
    {
        for (int j = 0; j < matrix1[0].size(); j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "矩阵2" << endl;
    for (int i = 0; i < matrix2.size(); i++)
    {
        for (int j = 0; j < matrix2[0].size(); j++)
        {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    matrix_add(matrix1, matrix2, matrix3);
    cout << "矩阵1+矩阵2" << endl;
    for (int i = 0; i < matrix3.size(); i++)
    {
        for (int j = 0; j < matrix3[0].size(); j++)
        {
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }
    //将matrix3里面所有的元素都置为0
    matrixSetZero(matrix3);
    matrix_sub(matrix1, matrix2, matrix3);
    cout << "矩阵1-矩阵2" << endl;
    for (int i = 0; i < matrix3.size(); i++)
    {
        for (int j = 0; j < matrix3[0].size(); j++)
        {
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }
    //将matrix3里面所有的元素都置为0
    matrixSetZero(matrix3);
    matrix_mul(matrix1, matrix2, matrix3);
    cout << "矩阵1*矩阵2" << endl;
    for (int i = 0; i < matrix3.size(); i++)
    {
        for (int j = 0; j < matrix3[0].size(); j++)
        {
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}