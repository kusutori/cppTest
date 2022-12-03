#include <iostream>
#include <vector>
using namespace std;

/*二、运算符重载（25分）
定义矩阵类Matrix，只包含一个私有数据vector<vector <int>> data，完成：
1) 设计构造函数，支持在主函数创建两个2*2的矩阵并初始化赋值；
2) 重载操作符+，完成两个矩阵的相加；
3) 重载操作符<<， 完成一个矩阵的输出。
4) 在主函数中，写出调用语句，测试1) – 3) 的功能。
*/

class Matrix
{
private:
    vector<vector<int>> data;

public:
    Matrix(vector<vector<int>> d) : data(d) {}
    Matrix operator+(Matrix &m)
    {
        vector<vector<int>> result;
        for (int i = 0; i < data.size(); i++)
        {
            vector<int> temp;
            for (int j = 0; j < data[i].size(); j++)
            {
                temp.push_back(data[i][j] + m.data[i][j]);
            }
            result.push_back(temp);
        }
        return Matrix(result);
    }
    friend ostream &operator<<(ostream &os, Matrix &m);
};

ostream &operator<<(ostream &os, Matrix &m)
{
    for (int i = 0; i < m.data.size(); i++)
    {
        for (int j = 0; j < m.data[i].size(); j++)
        {
            os << m.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

int main()
{
    vector<vector<int>> data1 = {{1, 2}, {3, 4}};
    vector<vector<int>> data2 = {{5, 6}, {7, 8}};
    Matrix m1(data1);
    Matrix m2(data2);
    Matrix m3 = m1 + m2;
    cout << "矩阵1：" << endl;
    cout << m1;
    cout << "矩阵2：" << endl;
    cout << m2;
    cout << "矩阵1+矩阵2：" << endl;
    cout << m3;
    return 0;
}