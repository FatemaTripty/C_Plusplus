#include<iostream>
using namespace std;

int main()
{

    int arr[] = {17,19,28,30,45,55,58,61};
    int item;
    cout<<"the number you want to search : ";
    cin>>item;

    int n = sizeof(arr)/sizeof(int);
    int l=0 , r = n-1; int mid ;

    while(l<=r)
    {
        mid =(l+r)/2;

        if(arr[mid]==item)
        {
            cout<<"Item is fouund at index : "<<(mid+1);
            exit(0);

        }
        else if(item>arr[mid])
        {
            l = mid +1 ;

        }
        else if (item< arr[mid])
        {
            r = mid -1;
        }
    }
    cout <<"Number is not found."<<endl;
    return 0;
}











