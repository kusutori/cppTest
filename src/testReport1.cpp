#include <iostream>
using namespace std;

/*一、多态程序设计题（25分）
定义基类Shape，由它派生出2个类：Circle类， Rectangle类。
1) 每个类至少设计一种构造函数，以便主函数的定义对象语句调用。Circle类中定义私有成员圆心坐标和半径。 Rectangle类中定义私有成员长和宽。
2）Cricle和Rectangle类分别定义各自的成员函数area，完成圆面积和矩形面积的计算。
3）实现多态：设计全局函数compute_area作为公共接口，根据实参数据类型计算面积。
4）主函数定义Circle类、Rectangle类对象，完成初始赋值。写出全局函数compute_area的调用语句，测试2）、3）函数的功能。
*/

class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}
    virtual double area() = 0;
};

class Circle : public Shape
{
private:
    double x, y, radius;

public:
    Circle(double x, double y, double r) : x(x), y(y), radius(r) {}
    double area() { return 3.14 * radius * radius; }
};

class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() { return length * width; }
};

// double compute_area(Shape *s)
// {
//     return s->area();
// }

double compute_area(Shape &s)
{
    return s.area();
}

int main()
{
    Circle c(0, 0, 1);
    Rectangle r(1, 2);
    cout << "通过各自的area函数计算面积：" << endl;
    cout << "圆面积：" << c.area() << endl;
    cout << "矩形面积：" << r.area() << endl;
    cout << "通过全局函数计算面积：" << endl;
    cout << "圆面积：" << compute_area(c) << endl;
    cout << "矩形面积：" << compute_area(r) << endl;
    return 0;
}