#include <iostream>
#include "linkedlist.h"

using namespace std;

int main()
{
    linkedlist student;
    student.studentinsert("Hossam Mohamed","CS");
    student.courseinsert("DS",100,"A+",4);
    student.courseinsert("OOP",89,"A",3.7);
    student.courseinsert("Stat",70,"C+",2.7);
    student.courseinsert("Math",95,"A+",4);

    student.studentinsert("Mohamed Ali","IS");
    student.courseinsert("DS",100,"A",3.7);

    student.studentinsert("Seif Mahmoud","DS");

    student.studentinsert("Ahmed Abd El-Rahman","AI");
    student.courseinsert("Software-2",50,"D",2);
    student.courseinsert("AI",98,"A",4);
    student.courseinsert("Network",98,"A+",4);
    student.courseinsert("Math-2",83,"B+",3.3);
    student.courseinsert("Math-3",100,"A+",4);

    student.studentinsert("Mahmoud Abd El-Rahman","IS");
    student.courseinsert("Software-1",80,"B+",3.3);
    student.courseinsert("IS",64,"D+",2.2);

    student.studentinsert("Abd El-Rahman Seif","CS");
    student.courseinsert("Software-2",78,"B",3);
    student.courseinsert("IT",98,"D",4);

    student.print();
    return 0;
}
