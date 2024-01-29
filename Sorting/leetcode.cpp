#include<iostream>
#include<string>
using namespace std;


int main()
{
    string s = "rana saad khan";
    char arr[4];
    for(int i=0;i<4;i++)
    {
        arr[i] = s[i];
    }
    cout<<arr<<endl;
}