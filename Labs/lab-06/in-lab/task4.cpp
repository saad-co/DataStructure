#include <iostream>
#include <string>
using namespace std;

void func(string s, int n)
{
    if (n == 0)
    {
        cout << s << endl;
    }
    else
    {
        func(s + "0", n - 1);
        func(s + "1", n - 1);
    }
}

int main()
{
    int n = 2;
    func("",n);
    return 0;
}

// t.c is O(n)
//  s.c is O(n)
