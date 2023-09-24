#include<iostream>
using namespace std;
int main()
{
    string c;
    cout<<"Enter input : ";
    cin>>c;
    cout<<endl;
    int count = 0;
    for(int i = 0; i<c.size(); i++)
    {
        if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/'||c[i]=='%'||c[i]=='>'||c[i]=='<'||c[i]=='!'||c[i]=='^')
        {
            count++;
            cout<<"Operator is"<<count<<" : "<<c[i]<<endl;
        }

    }

}

