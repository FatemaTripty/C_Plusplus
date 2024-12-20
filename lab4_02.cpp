#include<iostream>
using namespace std;

int main()
{
    int arr[] = {7,5,12,8,4,15};
    int minimum;
    int temp;

    for (int i =0 ; i<6 ; i++)
    {

        minimum = i;


        for( int j = i+1 ; j< 5; j++)
        {
            if(arr[j] < arr[minimum])
            {
              minimum =j;
            }
        }
        if(arr[i] > arr[minimum])
        {

                temp = arr[i];
                arr[i] = arr[minimum];
                arr[minimum]=temp;
        }
}
        for(int i = 0;i<6 ; i++)
        {
            cout<<arr[i]<<" ";
        }

    return 0;

}
