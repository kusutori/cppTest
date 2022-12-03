#include <iostream>
using namespace std;

class Rectangle
{
private:
    int x1;
    int y1;
    int x2;
    int y2;

public:
    Rectangle(int x1, int y1, int x2, int y2);
    Rectangle(int x2, int y2);
    ~Rectangle();
    int print();
};

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    cout << "Rectangle对象成功创建" << endl;
}

Rectangle::~Rectangle()
{
    cout << "Rectangle对象成功销毁" << endl;
}

Rectangle::Rectangle(int x2, int y2)
{
    this->x1 = 0;
    this->y1 = 0;
    this->x2 = x2;
    this->y2 = y2;
    cout << "左上角位于原点的默认Rectangle对象成功创建" << endl;
}

int Rectangle::print()
{
    cout << "Rectangle对象的左上角坐标为(" << this->x1 << "," << this->y1 << ")" << endl;
    cout << "Rectangle对象的右下角坐标为(" << this->x2 << "," << this->y2 << ")" << endl;
    return 0;
}

int main()
{
    Rectangle rec1(1, 2, 3, 4);
    rec1.print();
    Rectangle rec2(5, 6);
    rec2.print();
}