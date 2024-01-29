#include <iostream>
using namespace std;

void bubble_sort(int *arr, int length) // bubbles the highest element at the end of array
{
    int counter = 0;
    while (counter <= length - 1)
    {
        for (int i = 0; i < length - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        counter++;
    }
}

void insertion_sort(int *arr, int len) // insert the element at its correct postion
{
    for (int i = 1; i < len; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

void selection_sort(int *arr, int len) // selects the smallest element from the array and swap it with the first element
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j], arr[i]);
            }
        }
    }
}

void merge(int *arr, int left, int mid, int right)
{
    int N1 = mid - left + 1;
    int N2 = right - mid;
    int *leftArr = new int[N1];
    int *rightArr = new int[N2];

    for (int i = 0; i < N1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < N2; i++)
    {
        rightArr[i] = arr[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < N1 && j < N2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < N1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < N2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void merge_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
    }
}


int main()
{
    int arr[7] = {5, 11, 7, 2, 1, 5, 8};
    merge_sort(arr,0,6);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}