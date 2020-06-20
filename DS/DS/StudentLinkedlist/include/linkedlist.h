#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;
struct course
{
    string name;
    int total;
    string grade;
    double point;
    course* next;
};
struct lisst
{
    string name;
    string dept;
    int courses_num=0;
    course* course_list=NULL;
    lisst* next;
};
class linkedlist
{
    public:
        linkedlist(){}
        void studentinsert(string name,string dept)
        {
            lisst *temp_element=new lisst ;
            temp_element->name=name;
            temp_element->dept=dept;
            temp_element->course_list=NULL;
            temp_element->next=NULL;

            if(listhead==NULL)
            {
                listhead=temp_element;
                listtail=temp_element;
            }
            else
            {
                listtail->next=temp_element;
                listtail=listtail->next;
            }
        }
        void courseinsert(string name,int total,string grade,double point)
        {
            course *temp_element=new course ;
            temp_element->name=name;
            temp_element->total=total;
            temp_element->grade=grade;
            temp_element->point=point;
            temp_element->next=NULL;

            if(listtail->course_list==NULL)
            {
                listtail->course_list=temp_element;
                listtail->courses_num++;
            }
            else
            {
                course *next_element=new course ;
                next_element=listtail->course_list;
                while(true)
                {

                    if(next_element->next==NULL)
                        break;

                    next_element=next_element->next;
                }
                next_element->next=temp_element;

                listtail->courses_num++;
            }
        }
        void print()
        {
            lisst* print=new lisst;
            print=listhead;
            while(print)
            {
                cout<<"Student name: "<<print->name<<endl;
                cout<<"Student department: "<<print->dept<<endl;
                cout<<"Number of courses: "<<print->courses_num<<endl;
                cout<<"*****************************"<<endl;
                cout<<"_____________________________"<<endl;
                while(print->course_list)
                {
                    cout<<"Course name: "<<print->course_list->name<<endl;
                    cout<<"Course total: "<<print->course_list->total<<endl;
                    cout<<"Course grade: "<<print->course_list->grade<<endl;
                    cout<<"Course point: "<<print->course_list->point<<endl;
                    cout<<"_____________________________"<<endl;
                    print->course_list=print->course_list->next;

                }

                cout<<"-----------------------------"<<endl;
                print=print->next;
            }
        }
        virtual ~linkedlist(){}

    protected:

    private:
        lisst* listhead=NULL;
        lisst* listtail=NULL;
};

#endif // LINKEDLIST_H
