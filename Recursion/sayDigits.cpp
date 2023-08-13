#include<iostream>
#include<string>
using namespace std;


void sayDigit(string arr[],int n)
{
    if(n==0)
    {
        // cout<<"zero"<<" ";
        return;
    }
    int num = n%10;
    n = n/10;

    sayDigit(arr,n);

    cout<<arr[num]<<" ";

}


int main()
{
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n = 0;
    cin>>n;

    sayDigit(arr,n);

    return 0;

}