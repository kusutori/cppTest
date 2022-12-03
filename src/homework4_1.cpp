#include <iostream>
using namespace std;

/*一、输入一串字符串“adfrgTDGnb789cdEfl0de”，
存入到string对象中，删除string对象中所有的大写字符，
并输出删除大写字符后的字符串。（
可以使用迭代器，也可以使用下标方式）*/

int main()
{
    string str1 = "adfrgTDGnb789cdEfl0de";
    string str2 = str1;
    string str3(str1);
    for (int i = 0; i < str2.size(); i++)
    {
        if (str2[i] >= 'A' && str2[i] <= 'Z')
        {
            str2.erase(i, 1);
            i--;
        }
    }
    cout << "原始字符串" << str1 << endl;
    cout << "新字符串" << str2 << endl;
    return 0;
}