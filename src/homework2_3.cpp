#include <iostream>
using namespace std;

class Date
{
private:
    int year = 0;
    int month = 0;
    int day = 0;

public:
    Date(int year, int month, int day);
    Date(const Date &d);
    ~Date();
    int print();
};

Date::Date(int year, int month, int day)
{
    if (year >= 0 && year <= 9999)
    {
        if (month >= 1 && month <= 12)
        {
            switch (month)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (day >= 1 && day <= 31)
                {
                    this->year = year;
                    this->month = month;
                    this->day = day;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (day >= 1 && day <= 30)
                {
                    this->year = year;
                    this->month = month;
                    this->day = day;
                }
                break;
            case 2:
                if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                {
                    if (day >= 1 && day <= 29)
                    {
                        this->year = year;
                        this->month = month;
                        this->day = day;
                    }
                }
                else
                {
                    if (day >= 1 && day <= 28)
                    {
                        this->year = year;
                        this->month = month;
                        this->day = day;
                    }
                }
                break;
            }
        }
    }
    else
    {
        cout << "不是合法的日期" << endl;
        return;
    }
    cout << "日期对象创建成功" << endl;
    return;
}

Date::Date(const Date &d)
{
    this->year = d.year;
    this->month = d.month;
    this->day = d.day;
    cout << "日期对象通过拷贝被创建" << endl;
}

Date::~Date()
{
    cout << "日期对象被销毁" << endl;
}

int Date::print()
{
    cout << year << "年" << month << "月" << day << "日" << endl;
    return 0;
}

int main()
{
    Date date1(2022, 10, 22);
    Date date2(date1);
    date1.print();
    date2.print();
    return 0;
}