#include <iostream>

using namespace std;

void sort_arraies(int x[],int y[],int m,int n);
void print_arraies(int x[],int y[],int m,int n);
int main()
{

    int x[]={2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int y[]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    sort_arraies(x,y,10,10);
    print_arraies(x,y,10,10);

    int x1[]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int y1[]={1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    sort_arraies(x1,y1,10,10);
    print_arraies(x1,y1,10,10);

    int x2[]={1, 4, 7, 8, 10};
    int y2[]={2, 3, 9};

    sort_arraies(x2,y2,5,3);
    print_arraies(x2,y2,5,3);

    int x3[]={9, 100, 2000, 30000, 100000};
    int y3[]={2, 3, 9};

    sort_arraies(x3,y3,5,3);
    print_arraies(x3,y3,5,3);

return 0;
}
void sort_arraies(int x[],int y[],int m,int n)
{
    for(int i=0 ; i<m ;i++){
            for(int j=n-1 ;j>=0 ;j--){
                if(x[i]>y[j]){
                    swap(x[i],y[j]);
                }
            }
        }
}
void print_arraies(int x[],int y[],int m,int n)
{
    cout<<"---------------------------"<<endl;
        cout<<"the first array is"<<endl;
        for(int i=0 ; i<m ;i++){
            cout<<x[i]<<endl;
        }
        cout<<"---------------------------"<<endl;
        cout<<"the second array is"<<endl;
        for(int j=0 ; j<n ;j++){
            cout<<y[j]<<endl;
        }
}
