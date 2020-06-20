#include <iostream>
#include <queue>
#include <deque>
using namespace std;

template <class t>
    struct tree
    {
        t value;
        tree *right,*left;
        tree();
        tree(const t&v):value(v),left(NULL),right(NULL){}

    };
    template <class t>

class bt
{
         tree <t> *root;
        int lengh=0;
        queue<tree<int>*> q;
    int arr2[1000];

public:
    bt()
    {
        root=NULL;
    }
  void insertt(t item)
        {
            tree <t> *newtree=new tree <t>  (item);
            tree <t> *current;

            if(root == NULL)
            {
                root=newtree;
                q.push(root);
            }

            else
            {
                    current=q.front();
                    if(current->left==NULL)
                    {
                        current->left=newtree;
                        q.push(current->left);
                    }

                    else if(current->right==NULL)
                    {
                        current->right=newtree;
                        q.push(current->right);
                        q.pop();

                    }


            }
    }





     tree <t> *getroot()
    {
        return root;
    }

void preorder1(struct tree <t> *p)
    {
        int static x=0;
        if (p==NULL)
        {


            return;
        }

            cout<<p->value<<endl;
            preorder1(p->left);
            preorder1(p->right);

    }
void preorder()
{
    if(root!=NULL)

   preorder1(root);

}

void preorder(tree <t> *p)
{
    if(root!=NULL)

   preorder1(p);

}


   void inorder1(tree <t> *p)
    {
        int static x=0;
        if (p==NULL)
        {
            return;
        }

            inorder1(p->left);
            cout<<p->value<<endl;
            inorder1(p->right);

    }
void inorder(tree <t> *p)
{
    if(root!=NULL)

    inorder1(p);

}
void inorder()
{
    if(root!=NULL)

    inorder1(root);

}



   void postorder1(tree <t> *p)
    {
        int static x=0;
        if (p==NULL)
        {
            return;
        }

            postorder1(p->left);
            postorder1(p->right);
            cout<<p->value<<endl;


    }
void postorder()
{
    if(root!=NULL)

    postorder1(root);

}

void postorder(tree <t> *p)
{
    if(root!=NULL)

    postorder1(p);

}
void doflipping(tree <t> *treed)
{
    if(treed==NULL)
        return;
    swap(treed->right,treed->left);

   // if(treed->left!=NULL)
        flipping(treed->left);
    //if (treed->right!=NULL)
        flipping(treed->right);

}

void flipping (tree <t> *p)
{
        doflipping(p);

}


void flipping ()
{
        doflipping(root);

}
void highstvalue(tree <t> *root)
    {
        int j=0;
        int static z=1;
        int maxi=NULL;
        static int k=2;
        if(root==NULL)
            return;
        queue <tree <t> *>q;
        deque <int>q2;
        deque <int>q3;
        q.push(root);
        q3.push_back(root->value);
        while(!q.empty())
        {
            tree <t> *curr=q.front();

            if(curr->left!=NULL)
               {
                   q.push(curr->left);
                q2.push_back(curr->left->value);
               }

            else
                j++;

            if(curr->right!=NULL)
                {
                    q.push(curr->right);
                    q2.push_back(curr->right->value);
                }

            else
                j++;

                q.pop();




                 while (q2.size()>=k-j&&j!=k)
                {
                    //cout<<j;
                    for(int i=0;i<k-j;i++)
                    {
                            maxi=max((q2[i]),maxi);
                          q2.pop_back();
                    }
                 //   cout<<"  MM"<<maxi <<"   ";
                    q3.push_back(maxi);
                    k*=2;
                    j=0;
                    z++;
                    maxi=NULL;

                }


        }
        for(int i=0;i<q3.size();i++)
        {
            cout<<q3[i]<<"  ";
        }

    }
void printhighstvalue()
    {
        cout<<"[";
        highstvalue(root);
        cout<<"]";
    }

 int leaveNo()
        {
            return leavecount(root);
        }
        int leavecount(tree<int>* p)
        {
            if(p!=NULL)
            {
                if((p->right!=NULL)||(p->left!=NULL))
                {
                    return leavecount(p->left)+leavecount(p->right);
                }
            else
                 return 1;
            }

        }

  void brunchesSum()
    {
        int arr[1000];
        int sum=0;
        int arr3[leavecount(root)];
        searchforleave(root,arr,0,arr3);
        for (int i=0 ;i<leavecount(root) ;i++)
       {
           sum+=arr3[i];
       }
       cout<<"sum= "<<sum<<" (";
       for (int i=0 ;i<leavecount(root) ;i++)
       {
           cout<<arr3[i];
           if(i!=leavecount(root)-1)
            cout<<"+";
       }
       cout<<")"<<endl;
    }
    void Path(int arr[],int sizee,int arr3[])
    {
        static int index=-1;
        index++;
        int y=sizee-1;
        cout<<"path->";
        for(int i=0 ;i<sizee ;i++)
        {
            cout<<arr[i];
            if(i!=sizee-1)
                cout<<"->";
            arr2[i]=1;
            for(int j=0 ; j<y ; j++)
            {
                arr2[i]*=10;
            }
            y--;
            arr2[i]*=arr[i];

        }
       for(int i=0 ;i<sizee-1; i++)
       {
           arr2[0]+=arr2[i+1];
       }
       arr3[index]=arr2[0];
       cout<<" encodes "<<arr3[index]<<endl;
       cout<<"------"<<endl;

    }
    void searchforleave(tree<int>* p,int arr[],int x,int arr3[])
    {
        if (p!=NULL)
        {
            arr[x]=p->value;
            x++;
            if(p->left!=NULL || p->right!=NULL)
            {

                    searchforleave(p->left,arr,x,arr3);
                    searchforleave(p->right,arr,x,arr3);
            }
            else
            {
                Path(arr,x,arr3);
            }

        }

    }




};

int main()
{
bt<int>x;
  x.insertt(1);
  x.insertt(2);
  x.insertt(3);
  x.insertt(4);
  x.insertt(5);

cout<<"TEST CASE 1"<<endl;
cout<<"preorder"<<endl;
 x.preorder();
 cout<<endl<<"postorder"<<endl;
 x.postorder();
  cout<<endl<<"inorder"<<endl;
 x.inorder();
 cout<<endl<<"Flipping and print by inorder"<<endl;
 x.flipping();
 x.inorder();
 cout<<endl<<"Largest value"<<endl;
 x.printhighstvalue();
 cout<<endl;
   x.brunchesSum();

    cout<<endl<<endl;
    cout<<"TEST CASE 2"<<endl;

    bt<int>y;
  y.insertt(1);
  y.insertt(2);
  y.insertt(3);
  y.insertt(4);
  y.insertt(5);
  cout<<"preorder for leftnode"<<endl;
 y.preorder(y.getroot()->left);
 cout<<endl<<"postorder for leftnode"<<endl;
 y.postorder(y.getroot()->left);
  cout<<endl<<"inorder for leftnode"<<endl;
 y.inorder(y.getroot()->left);
 cout<<endl<<"Flipping for leftnode and print by inorder"<<endl;
 y.flipping(y.getroot()->left);
 y.inorder();

    return 0;
}
