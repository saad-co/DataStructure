#include<iostream>
#include<string>
using namespace std;


void reverse(int i,int j,string &str)
{
    if(i>j)
    {
        return;
    }
    swap(str[i],str[j]);
    i++;j--;
    reverse(i,j,str);
}


int main()
{
    string s = "abcde";
    int i = 0;
    int j = s.length()-1;
    reverse(i,j,s);
    cout<<s<<" "<<endl;
    return 0;
}