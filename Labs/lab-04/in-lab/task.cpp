#include <iostream>

using namespace std;

int fnLinearSearch(int Array[], unsigned int Size, int SearchKey) {
    for (unsigned int i = 0; i < Size; i++) {
        if (Array[i] == SearchKey) {
            return i; 
        }
    }
    return -1; 
}


int main()
{
    const int sizee = 10;
    int arr[sizee];
    for(int i=0;i<sizee;i++)
    {
        arr[i] = rand()%10;
    }
    for(int i=0;i<sizee;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int res = arr[3];
    cout<<res<<endl;
    cout<<fnLinearSearch(arr,8,res)<<endl;
    // if(res == fnLinearSearch(arr,8,res))
    // {
    //     cout<<"ok";
    // }
    // else
    // {
    //     cout<<"not ok";
    // }
}