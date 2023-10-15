#include <iostream>
using namespace std;

int squares_sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * n + squares_sum(n - 1);
    }
}

int main()
{
    int n = -3;
    cout << "Input: " << n << endl;
    cout << "Output: " << squares_sum(n) << endl;
    return 0;
}

// t.c is O(n)
// s.c is O(n)
