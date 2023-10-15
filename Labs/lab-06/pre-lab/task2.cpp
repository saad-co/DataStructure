#include <iostream>
using namespace std;

int Power(int n, int p)
{
    if (p == 1)
    {
        return n;
    }
    int res = n * Power(n, p - 1);
    return res;
}

int main()
{
    int val = Power(25, 2);
    cout << val << endl;
    return 0;
}

// time complexity of the code O(p)
// Space complexity of the codeO(p)