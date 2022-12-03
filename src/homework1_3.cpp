#include <iostream>
#include <vector>
using namespace std;

int add(vector<vector<int>> &result, vector<vector<int>> &source1, vector<vector<int>> &source2)
{
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            result[i][j] = source1[i][j] + source2[i][j];
        }
    }
    return 0;
}

int showMatrix(vector<vector<int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int main()
{
    const int N = 4;
    vector<vector<int>> result(N, vector<int>(N));
    vector<vector<int>> source1(N, vector<int>(N));
    vector<vector<int>> source2(N, vector<int>(N));
    cout << "请输入第一个矩阵" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> source1[i][j];
        }
    }
    cout << "请输入第二个矩阵：" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> source2[i][j];
        }
    }
    add(result, source1, source2);
    cout << "第一个矩阵为：" << endl;
    showMatrix(source1);
    cout << "第二个矩阵为：" << endl;
    showMatrix(source2);
    cout << "两个矩阵相加后的结果为：" << endl;
    showMatrix(result);
    return 0;
}
