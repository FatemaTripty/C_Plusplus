#include<iostream>
using namespace std;


class Stack
{
   public:
       int top;
       int size;
       int *a;


       Stack(int size)
       {
           this-> size = size;
           a = new int [top];
           top = -1;

       }
       void push(int x)
       {
           if (size - top > 1)
            {
            top++;
           a[top] = x;
       }
       else
        {
            cout<<"Stack is overflow  ";


       }
       }
  bool isFull()
  {
      if(top == size)
      {
          cout<<"Array is ful"<<endl;
      }
  }
       void pop()

       {

           if(top>=0)
           {

               top--;
           }

           else
           {
              cout<<"Stack is underflow";
           }

       }

       bool isEmpty()
       {
           if(top == -1)
           {
               cout<<"The array is empty "<<endl;
               return true;
           }
           else
           {
               return false;
           }
       }

       void change(int pos,int val)
       {
           a[pos]= val;
           cout<<"The changed value is : "<<val<<endl;
           cout<<"The changed index is : "<<pos<<endl;

       }



void showDetails()
{

    for(int i = top; i >=0; i--)
    {
        cout<<a[i]<<" ";
    }
}

};

int main()
{
    Stack s(5);
    cout<<"Pushed elements are : ";
    s.push(9);
    s.push(7);
    s.push(5);
    s.push(10);
    s.push(11);
    //s.push(11);


    s.showDetails();

    cout<<""<<endl;
    cout<<"Poped elements are : ";


    s.pop();
    s.pop();


    s.showDetails();
    cout<<endl;

    s.change(1,5);

    cout<<"After changing element : ";
    s.showDetails();

    s.isEmpty();
}
