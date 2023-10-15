#include <iostream>
using namespace std;

void printing(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << "*";
    printing(n - 1);
}

void printPattern(int rows, int currentRow = 1)
{

    if (currentRow > rows)
    {
        return;
    }

    printing(currentRow);

    cout << endl;

    printPattern(rows, currentRow + 1);
}

int main()
{
    int rows = 10;
    printPattern(rows);
    return 0;
}

// t.c = O(n^2);
// s.c = O(n^2);
