#include <bits/stdc++.h>

using namespace std;


int main()
{
    string str ;
    cout<<"Give a string for reversing : ";
    cin>>str;
    stack<char> st;
    cout<<endl;

    for(int i = 0; i < str.size(); i++){
        st.push(str[i]);
    }

    string ans = "";
    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }
    cout<<"Given String is : "<<str<<endl;
    cout<<"Reversed string is : "<<ans<<endl;
    return 0;
}
