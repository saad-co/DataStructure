#include <iostream>
using namespace std;

// binary search function without recursion
int binary_search(int *arr, int key, int size)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (arr[middle] == key)
        {
            return middle;
        }
        else if (key > arr[middle])
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }
    return -1;
}

// binary search function with recursion
int binary_search(int *arr, int key, int low, int high)
{
    if (low <= high)
    {
        int middle = (low + high) / 2;
        if (arr[middle] == key)
        {
            return middle;
        }
        else if (key < arr[middle])
        {
            high = middle - 1;
            binary_search(arr, key, 0, high);
        }
        else
        {
            low = middle + 1;
            binary_search(arr, key, low, high);
        }
    }
}

int main()
{
    int arr[10] = {1, 23, 24, 36, 44, 77, 89, 100, 110, 111};
    int value = binary_search(arr, 89, 0, 10);
    if (value != -1)
    {
        cout << "value found at index: : " << value << endl;
    }
    else
    {
        cout << "value not found: " << endl;
    }

    return 0;
}