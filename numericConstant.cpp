#include<iostream>
#include<string.h>
using namespace std;
int main()

{
    string s;
    cout<<"Enter input : ";
    cin>>s;
    cout<<endl;
    int count=0;

   for(int i = 0;i<s.size();i++)
   {
       if( (s[i]=='0')||(s[i]=='1')||(s[i]=='2')||(s[i]=='3')||(s[i]=='4')||(s[i]=='5')||
          (s[i]=='6')||(s[i]=='7')||(s[i]=='8')||(s[i]=='9'))
       count++;
       else count--;
   }
   if(count==s.size())
    cout<<"Numeric constant "<<endl;

    else
        cout<<"Not numeric constant"<<endl;

}
