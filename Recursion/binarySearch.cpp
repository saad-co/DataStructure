#include<iostream>
using namespace std;

void print(int* arr,int s,int e)
{
    for(int i=s;i<e;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
}


bool biSe(int* arr, int s,int e, int k)
{
    print(arr,s,e);
    if(s>e)
    {
        return false;
    }
    int mid = s + (e-s)/2;
    cout<<"value of mid is: "<<arr[mid]<<endl;
    if(arr[mid] == k)
    {
        return true;
    }
    if(arr[mid]<k)
    {
        biSe(arr,mid+1,e,k);
    }
    else
    {
        biSe(arr,s,mid-1,k);
    }
}


int main()
{
    int arr[11] = {1,2,3,4,5,6,7,8,9,10,222};
    if(biSe(arr,0,11,222))
    {
        cout<<"element is found in the array :"<<endl;
    }
    else
    {
        cout<<"element is not found in the array: "<<endl;

    }

    return 0;
}