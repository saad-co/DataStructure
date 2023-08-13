#include <iostream>
// #include<array>

using namespace std;

int sum(int *arr, int size)
{
      if (size == 0)
    {
        return 0; // Base case: return 0 for an empty array
    }

    // Recursive case:
    // Add the current element to the sum of the rest of the array
    return arr[0] + sum(arr + 1, size - 1);
}

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int ans = sum(arr, 5);
    cout << "sum is: " << ans;

    return 0;
}