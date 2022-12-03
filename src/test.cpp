#include <iostream>
#define Pi 3.14
using namespace std;

class Shape
{
public:
    virtual double area() { return 0; }
    virtual void show(){};
};

class Point
{
private:
    int x;
    int y;

public:
    Point() : x(0), y(0) {}
    Point(int a = 0) : x(a), y(0) {}
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    Point(Point &p)
    {
        x = p.x;
        y = p.y;
    }
    ~Point() {}
};

class Circle : public Shape
{
private:
    Point p;
    int r;

public:
    Circle(int a = 0, int b = 0, int c = 0) : p(a, b), r(c) {}
    ~Circle() {}
    double area() { return Pi * r * r; }
    void show() { cout << "Circle's area:" << this->area() << endl; }
};

class Rectangle : public Shape
{
private:
    int length;
    int width;

public:
    Rectangle(int a = 0, int b = 0) : length(a), width(b) {}
    ~Rectangle() {}
    double area() { return length * width; }
    void show() { cout << "Rectangle's area:" << this->area() << endl; }
};

void compute_area(Shape &Y)
{
    // Y.area();
    Y.show();
    // return Y.area();
}

int main()
{
    Circle A(1, 1, 4);
    Rectangle B(2, 9);
    compute_area(A);
    compute_area(B);
    return 1;
}
