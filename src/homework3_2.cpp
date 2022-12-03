#include <iostream>
#include <cstring>
using namespace std;

/*二、定义Document类，要求：
1) 包括私有数据：文档名name(char * 类型)，文档名大小name_size(unsigned int类型)，
文档名存储空间name_cap(unsigned int类型)；文档页数pages(int类型)；
2) 设计接收实参，对name和pages进行初始化的构造函数；
3) 设计拷贝构造函数和析构函数。
4) 在主函数测试2) – 3)的功能。
*/

class Document
{
private:
    char *name;
    unsigned int name_size;
    unsigned int name_cap;
    int pages;

public:
    Document(char *name, int pages)
    {
        this->name = name;
        this->pages = pages;
    }
    // Document(const Document &d)
    // {
    //     this->name = d.name;
    //     this->pages = d.pages;
    // }
    Document(const Document &d)
    {
        this->name = new char[strlen(d.name) + 1];
        strcpy(this->name, d.name);
        this->pages = d.pages;
    }
    ~Document()
    {
        delete[] name;
    }
    string getName()
    {
        return name;
    }
};

int main()
{
    char *name = new char[10];
    strcpy(name, "MyBook");
    Document d1(name, 10);
    cout << d1.getName() << endl;
    Document d2(d1);
    cout << d2.getName() << endl;
    return 0;
}
