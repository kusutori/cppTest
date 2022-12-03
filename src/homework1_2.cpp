#include <iostream>
#include <vector>
using namespace std;

int toUpper(vector<string> &vec)
{
    for (auto &str : vec)
    {
        if (str[0] >= 'a' && str[0] <= 'z')
        {
            str[0] = str[0] - 32;
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}

int main()
{
    vector<string> vec;
    cout << "请输入一段文本,按回车结束输入" << endl;
    for (string str; cin >> str;)
    {
        vec.push_back(str);
        if (cin.get() == '\n')
            break;
    }
    toUpper(vec);
    return 0;
}
