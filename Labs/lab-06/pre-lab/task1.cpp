#include <iostream>
using namespace std;

int Search(int *arr, int size, int elem)
{
    if (size <= 0)
    {
        return -1;
    }
    if (arr[size] == elem)
    {
        return size;
    }
    Search(arr, size - 1, elem);
}

int main()
{
    int array[5] = {1, 2, 10, 4, 5};
    int val = Search(array, 5, 3);
    cout << val << endl;
    return 0;
}


// time complexity O(n)
// Space complexity O(n)