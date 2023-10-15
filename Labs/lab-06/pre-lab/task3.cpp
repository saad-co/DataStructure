#include <iostream>
using namespace std;

int number_of_digits(int number)
{
    if (abs(number) == 0)
    {
        return 0;
    }
    return 1 + number_of_digits(number / 10);
}

int main()
{
    int val = number_of_digits(5000);
    cout<<val;
    return 0;
}

// time complexity of the code is O(d)
// space complecity of the code isO(d)