#include <iostream>
using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    // Point();
    Point(double x = 1, double y = 3);
    Point(const Point &p);
    ~Point();
    int print1();
    double getx();
    double gety();
    int set(double x, double y);
};

// Point::Point()
// {
//     this->x = 0;
//     this->y = 0;
//     cout << "默认Point对象成功创建" << endl;
// }

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
    cout << "Point对象成功创建" << endl;
}

Point::Point(const Point &p)
{
    this->x = p.x;
    this->y = p.y;
    cout << "Point对象通过拷贝成功创建" << endl;
}

Point::~Point()
{
    cout << "Point对象成功销毁" << endl;
}

int Point::print1()
{
    cout << "Point对象的坐标为(" << this->x << "," << this->y << ")" << endl;
    return 0;
}

double Point::getx()
{
    return this->x;
}

double Point::gety()
{
    return this->y;
}

int Point::set(double x, double y)
{
    this->x = x;
    this->y = y;
    return 0;
}

int print2(Point &p)
{
    cout << "Point对象的坐标为(" << p.getx() << "," << p.gety() << ")" << endl;
    return 0;
}

int main()
{
    Point p1;
    Point p2(1.3);
    Point p3(1.3, 5.6);
    p1.print1();
    p2.print1();
    p3.print1();
    print2(p1);
    print2(p2);
    print2(p3);
}