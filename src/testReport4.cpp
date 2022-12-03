#include <iostream>
using namespace std;

/*四、构造函数（25分）
定义类Point，含有x和y两个数据成员。完成：
1）定义构造函数，使得用户在main函数中能以如下方式初始化对象
int main(  ){
Point P1;
Point P2(1.3);
Point P3(1.3,5.6);
return 1;}
2）采用两个方式实现输出函数：①定义成员函数Print1输出点的坐标；②定义一般函数Print2输出点的坐标。
3) 在主函数中，写出调用语句，测试1）和2）的功能。
*/

class Point
{
private:
    double x, y;

public:
    Point() : x(0), y(0) {}
    Point(double x) : x(x), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
    void Print1()
    {
        cout << "x=" << x << ", y=" << y << endl;
    }
    friend void Print2(Point &p);
};

void Print2(Point &p)
{
    cout << "x=" << p.x << ", y=" << p.y << endl;
}

int main()
{
    Point P1;
    Point P2(1.3);
    Point P3(1.3, 5.6);
    P1.Print1();
    P2.Print1();
    P3.Print1();
    Print2(P1);
    Print2(P2);
    Print2(P3);
    return 0;
}