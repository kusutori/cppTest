#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int sum1(vector<int> &vecTemp)
{
    int sum = 0;
    for (int i = 0; i < vecTemp.size() - 1; i += 2)
    {
        sum = vecTemp[i] + vecTemp[i + 1];
        cout << sum << " ";
    }
    cout << endl;
    if (vecTemp.size() % 2 != 0)
    {
        cout << "最后一个元素没有求和，其值为：" << vecTemp[vecTemp.size() - 1] << endl;
    }
    return 0;
}

int sum2(vector<int> &vecTemp)
{
    int sum = 0;
    for (int i = 0; i < vecTemp.size() / 2; i++)
    {
        sum = vecTemp[i] + vecTemp[vecTemp.size() - 1 - i];
        cout << sum << " ";
    }
    if (vecTemp.size() % 2 != 0)
    {
        cout << vecTemp[vecTemp.size() / 2] << " ";
    }
    cout << endl;
    return 0;
}

int main()
{
    vector<int> vec;
    // cout << "请输入若干整数，输入回车结束输入：" << endl;
    //从文件读入若干整数，完成以上功能。
    ifstream inFile("../txt/data1.txt");
    if (!inFile)
    {
        cout << "文件打开失败" << endl;
        return 0;
    }
    cout << "文件打开成功" << endl;
    for (int temp; inFile >> temp;)
    {
        vec.push_back(temp);
        if (inFile.get() == '\n')
            break;
    }
    inFile.close();
    cout << "文件已关闭" << endl;
    cout << "调用sum1函数" << endl;
    sum1(vec);
    cout << "调用sum2函数" << endl;
    sum2(vec);
    return 0;
}
