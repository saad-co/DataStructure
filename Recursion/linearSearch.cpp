#include<iostream>
using namespace std;

bool find(int arr[],int key,int size)
{
    if(size == 0)
    {
        return false;
    }

    // bool f = false;
    if(arr[0] == key)
    {
        return true;
    }

    find(arr+1,key,size-1);
}


int main()
{
    int arr[5] = {3,5,9,8,6};
    bool found = find(arr,10,5);
    if(found)
    {
        cout<<"element is present: "<<endl;
    }
    else 
    {
        cout<<"element is not present is the arrya: "<<endl;
    }
    return 0;
}