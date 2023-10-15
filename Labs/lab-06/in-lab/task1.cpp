#include <iostream>
using namespace std;

int binomial(int n, int m)
{
    if (n == m || m == 0)
        return 1;
    else
        return binomial(n - 1, m) + binomial(n - 1, m - 1);
}


int main()
{
    int val = binomial(7,5);
    cout<<val;
    return 0;
}