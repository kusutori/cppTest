#include <iostream>
using namespace std;

/*二、定义学生类（Student），数据成员包括姓名（name）、学号（ID）、数学成绩（mathScore）、英语成绩（englishScore）。
定义全局变量：总人数（count）、数学总成绩（mathTotalScore）和英语总成绩（englishTotalScore）。至少满足以下功能：
1)	name是string类型，其它数据的数据类型为整型；所有数据成员为private访问权限。
2)	构造函数通过实参传递姓名、学号、数学成绩和英语成绩来构造对象。
3)	构造函数亦可以通过实参传递姓名、学号创建新对象。
4)	在主函数中定义2~3个学生类对象，分别显示学生的一般数据信息。正确输出所有学生的数学总成绩、英语总成绩和总人数。
*/

//全局变量,放入自己的命令空间myNameSpace中
namespace myNameSpace
{
    int count = 0;
    int mathTotalScore = 0;
    int englishTotalScore = 0;
}

class Student
{
private:
    string name;
    int ID;
    int mathScore;
    int englishScore;

public:
    Student(string name, int ID, int mathScore, int englishScore)
    {
        this->name = name;
        this->ID = ID;
        this->mathScore = mathScore;
        this->englishScore = englishScore;
        myNameSpace::count++;
        myNameSpace::mathTotalScore += mathScore;
        myNameSpace::englishTotalScore += englishScore;
    }
    Student(string name, int ID)
    {
        this->name = name;
        this->ID = ID;
        this->mathScore = 0;
        this->englishScore = 0;
        myNameSpace::count++;
        myNameSpace::mathTotalScore += mathScore;
        myNameSpace::englishTotalScore += englishScore;
    }
    void show()
    {
        cout << "name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "mathScore: " << mathScore << endl;
        cout << "englishScore: " << englishScore << endl;
    }
};

int main()
{
    Student s1("Tom", 1, 100, 100);
    Student s2("Jerry", 2, 90, 90);
    Student s3("Jack", 3);
    s1.show();
    s2.show();
    s3.show();
    cout << "数学总成绩: " << myNameSpace::mathTotalScore << endl;
    cout << "英语总成绩: " << myNameSpace::englishTotalScore << endl;
    cout << "总人数: " << myNameSpace::count << endl;
    return 0;
}