#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*二、定义学生类（Student），数据成员包括姓名（name）、学号（ID）、数学成绩（mathScore）、英语成绩（englishScore）、
总人数（count）、数学总成绩（mathTotalScore）和英语总成绩（englishTotalScore）。至少满足以下功能：
1)	所有数据成员为private型。其中，name是string类型，其它数据的数据类型为整型；总人数、数据总成绩、英语总成绩为静态数据成员。
2)	构造函数通过实参传递姓名、学号、数学成绩和英语成绩来构造对象。
3)	构造函数亦可以通过实参传递姓名、学号创建新对象。
4)	定义成员函数print输出非静态数据成员；定义静态成员函数print_total输出静态数据成员。
5)	在主函数中，定义vector<Student> 对象，存储多个学生的信息，并输出学生信息以及总人数等统计信息。
*/

class Student
{
private:
    string name;
    int ID;
    int mathScore;
    int englishScore;
    static int count;
    static int mathTotalScore;
    static int englishTotalScore;

public:
    Student(string name, int ID, int mathScore, int englishScore)
    {
        this->name = name;
        this->ID = ID;
        this->mathScore = mathScore;
        this->englishScore = englishScore;
        count++;
        mathTotalScore += mathScore;
        englishTotalScore += englishScore;
    }
    Student(string name, int ID)
    {
        this->name = name;
        this->ID = ID;
        this->mathScore = 0;
        this->englishScore = 0;
        count++;
        mathTotalScore += mathScore;
        englishTotalScore += englishScore;
    }
    void print()
    {
        cout << "学生姓名为:" << name << endl;
        cout << "学号为:" << ID << endl;
        cout << "数学成绩为:" << mathScore << endl;
        cout << "英语成绩为:" << englishScore << endl;
    }
    static void print_total()
    {
        cout << "学生总数为:" << count << endl;
        cout << "数学总成绩为:" << mathTotalScore << endl;
        cout << "英语总成绩为:" << englishTotalScore << endl;
    }
};

int Student::count = 0;
int Student::mathTotalScore = 0;
int Student::englishTotalScore = 0;

int main()
{
    vector<Student> students;
    students.push_back(Student("张三", 1, 100, 100));
    students.push_back(Student("李四", 2, 90, 90));
    students.push_back(Student("王五", 3));
    for (auto &student : students)
    {
        student.print();
    }
    Student::print_total();
    return 0;
}