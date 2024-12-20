#include<iostream>
using namespace std;

/*void swap(int *arr,int *b)
{
    int temp;
    temp = *arr;
    *arr = *b;
    *b = temp;

}
*/
int main()


{

    int arr[]={2,5,8,13,17,71,38,52,19};
    int n=sizeof(arr)/sizeof(int);

    for (int i = 0; i<n ; i++)
    {
        for(int j = 0; j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
               // swap(&arr[j],&arr[j+1]);


                  int t;
                  t = arr[j];
                  arr[j] =arr[j+1];
                  arr[j+1] = t;
            }


            else {
                continue;
            }
        }


    }
    for (int i = 0 ;i<n ;i++){
    cout<<arr[i]<<" ";
    }

}
