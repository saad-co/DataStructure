#include <iostream>
using namespace std;

string reverse(string s, int len)
{
    if (len < 0)
    {
        return "";
    }

    string res = s[len] + reverse(s, len - 1);
    return res;
}

int main()
{
    string n = "anas irfan";
    string r = reverse(n,10);
    cout<<r<<endl;

    return 0;
}

// time complexity of the code is O(n)
// space complexity of the code is O(n)