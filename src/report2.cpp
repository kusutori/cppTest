#include <iostream>
using namespace std;

/*题目 20 实数和复数的运算器 (1 人/组)
功能要求：
(1) 定义运算器类。
(2) 实现加减乘除运算。
(3) 运算符重载。
(4) 从文件读取，并写回结果。
(5) 自设计功能。
设计要求：
(1) 合理的类设计，各个功能模块要求用函数实现；
(2) C++语言实现；
(4) 函数设计符合日常生活习惯，用户使用体验好；
(5) 程序代码加注释
*/

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}
    Complex operator+(Complex &c)
    {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(Complex &c)
    {
        return Complex(real - c.real, imag - c.imag);
    }
    Complex operator*(Complex &c)
    {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }
    Complex operator/(Complex &c)
    {
        return Complex((real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag), (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag));
    }
    friend ostream &operator<<(ostream &os, Complex &c);
};

ostream &operator<<(ostream &os, Complex &c)
{
    os << c.real << " + " << c.imag << "i";
    return os;
}

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;
    Complex c6 = c1 / c2;
    cout << c1 << " + " << c2 << " = " << c3 << endl;
    cout << c1 << " - " << c2 << " = " << c4 << endl;
    cout << c1 << " * " << c2 << " = " << c5 << endl;
    cout << c1 << " / " << c2 << " = " << c6 << endl;
    return 0;
}
