#include <iostream>

int binary_search(int *arr, int left, int right, int target)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            return binary_search(arr, left, mid - 1, target);
        }
        else
        {
            return binary_search(arr, mid + 1, right, target);
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 7, 10, 14, 18, 23, 27};
    int target = 14;
    int left = 0;
    int right = sizeof(arr) / sizeof(arr[0]) - 1;
    int result = binary_search(arr, left, right, target);

    if (result != -1)
    {
        std::cout << "Element is present at index " << result << std::endl;
    }
    else
    {
        std::cout << "Element is not present in array" << std::endl;
    }

    return 0;
}

// time complexity of the code is O(log n)
// space complexity of the code is O(log n)
