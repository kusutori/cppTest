#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
private:
    unsigned int row;
    unsigned int col;
    vector<vector<int>> data;

public:
    Matrix() {}
    ~Matrix() {}
    int getrow() { return row; }
    int getcol() { return col; }
    int get(int a, int b) { return data[a][b]; }
    Matrix operator+(const Matrix &A);
    friend int operator>>(istream &in, Matrix &B);
};

int operator>>(istream &in, Matrix &B)
{
    cout << "行数:";
    in >> B.row;
    cout << "列数:";
    in >> B.col;
    cout << "矩阵:" << endl;
    B.data.resize(B.row);
    for (unsigned int i = 0; i < B.row; i++)
    {
        B.data[i].resize(B.col);
        for (unsigned int j = 0; j < B.col; j++)
        {
            in >> B.data[i][j];
        }
    }
    cout << "矩阵输入完成" << endl;
    return 1;
}

Matrix Matrix::operator+(const Matrix &B)
{
    Matrix temp;
    if (B.row != row || B.col != col)
        cout << "相加的矩阵行列不匹配！" << endl;
    temp.row = row;
    temp.col = col;
    temp.data.resize(temp.row);
    for (unsigned i = 0; i < row; i++)
    {
        temp.data[i].resize(temp.col);
        for (unsigned j = 0; j < col; j++)
        {
            temp.data[i][j] = data[i][j] + B.data[i][j];
        }
    }
    return temp;
}

ostream &operator<<(ostream &ou, Matrix &B)
{
    for (int i = 0; i < B.getrow(); i++)
    {
        for (int j = 0; j < B.getcol(); j++)
        {
            ou << B.get(i, j) << "  ";
        }
        ou << endl;
    }
    return ou;
}

int main()
{
    Matrix a, b, c;
    cin >> a;
    cout << "第一个矩阵构造完成" << endl;
    cin >> b;
    cout << "第二个矩阵构造完成" << endl;
    c = a + b;
    cout << "两个矩阵的和为:" << endl;
    cout << c;
    return 1;
}
