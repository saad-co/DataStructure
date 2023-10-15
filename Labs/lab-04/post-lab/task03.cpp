#include <iostream>
using namespace std;

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int mergedArray[])
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            mergedArray[k++] = arr1[i++];
        }
        else
        {
            mergedArray[k++] = arr2[j++];
        }
    }

    while (i < size1)
    {
        mergedArray[k++] = arr1[i++];
    }
    while (j < size2)
    {
        mergedArray[k++] = arr2[j++];
    }
}

int main()
{
    int arr1[] = {2, 5, 8, 12, 16};
    const int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {4, 7, 9, 10, 14, 18};
    const int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int mergedArray[size1 + size2];

    mergeSortedArrays(arr1, size1, arr2, size2, mergedArray);

    cout << "Merged Sorted Array: [";
    for (int i = 0; i < size1 + size2; ++i)
    {
        cout << mergedArray[i];
        if (i < size1 + size2 - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
