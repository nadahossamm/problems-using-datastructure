#include <iostream>
#include <deque>
using namespace std;

void Balanced(string s);
int main()
{
    Balanced("{()}[][{()()}()]");
    Balanced("{(])");
    Balanced("({}{}{{}}[]{{[][][]}})()()");
    Balanced("{}()[]");
    Balanced(")({}{}[]");

    return 0;
}
void Balanced(string s)
{
    deque <int> dq;
    for(int i=0;i<s.size();i++)
    {
        dq.push_back(s[i]);
    }
    int y=0;
    for(int i=0;i<s.size();i++)
    {
        int x=i+1;

        while (x<=s.size())
        {
            if(dq[i]==0)
            {
                break;
            }
           if((dq[i]=='['&&dq[x]==']')||(dq[i]=='('&&dq[x]==')')|| (dq[i]=='{'&&dq[x]=='}'))
            {
          //      cout<<"1"<<endl;

                dq[i]=dq[x]=0;
                break;

            }
            else
            {
                x=x+2;
            }
        }

    }
for(int i=0;i<s.size();i++)
{
    if(dq[i]!=0)
        y=1;

}
    if(y==0)
    {
        cout<<"Balanced"<<endl;
    }
    else
        cout<<"NOt Balanced"<<endl;

}
