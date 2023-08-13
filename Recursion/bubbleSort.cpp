#include<iostream>
using namespace std;

void sort(int *arr,int n)
{
    if(n==0 || n==1)
    {
        return;
    }

    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
    sort(arr,n-1);
}


int main()
{
    int arr[8] = {1,0,36,2,6,71,3,52};
    sort(arr,8);
    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}