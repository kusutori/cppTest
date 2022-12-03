#include <iostream>
using namespace std;

class Student
{
public:
    Student(string SN)
    {
        Name = SN;
        Sum++;
    }
    void printInfo()
    {
        cout << "The sum of students is " << Sum << endl;
        cout << "The student’s name is " << Name << endl;
    }

private:
    string Name;
    static int Sum;
};

int Student::Sum = 0;

void main()
{
    Student S1("Zhang San"), S2("Wang Qing”");
    S1.printInfo();
    S2.printInfo();
}
