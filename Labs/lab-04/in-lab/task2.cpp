#include <iostream>
#include <chrono>
using namespace std;
int fnLinearSearch(int Array[], unsigned int Size, int SearchKey)
{
    for (unsigned int i = 0; i < Size; i++)
    {
        if (Array[i] == SearchKey)
        {
            return i;
        }
    }
    return -1;
}

int fnBinarySearch(int Array[], unsigned int Size, int SearchKey)
{
    int left = 0;
    int right = Size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (Array[mid] == SearchKey)
        {

            while (mid > 0 && Array[mid - 1] == SearchKey)
            {
                mid--;
            }
            return mid;
        }
        else if (Array[mid] < SearchKey)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

void fnBubbleSort(int Array[], unsigned int Size, int SortKey)
{
    for (unsigned int i = 0; i < Size - 1; i++)
    {
        for (unsigned int j = 0; j < Size - i - 1; j++)
        {
            if ((SortKey == 0 && Array[j] > Array[j + 1]) ||
                (SortKey != 0 && Array[j] < Array[j + 1]))
            {

                int temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }
}

void fnSelectionSort(int Array[], unsigned int Size, int SortKey)
{
    for (unsigned int i = 0; i < Size - 1; i++)
    {
        unsigned int minIndex = i;
        for (unsigned int j = i + 1; j < Size; j++)
        {
            if ((SortKey == 0 && Array[j] < Array[minIndex]) ||
                (SortKey != 0 && Array[j] > Array[minIndex]))
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = Array[i];
            Array[i] = Array[minIndex];
            Array[minIndex] = temp;
        }
    }
}
int main()
{
    const int sizee = 10;
    int arr[sizee];
    for (int i = 0; i < sizee; i++)
    {
        arr[i] = rand() % 10;
    }
    int res = arr[5];
    // Get the current time before executing your code
    auto start_time = chrono::high_resolution_clock::now();
    fnBubbleSort(arr,sizee,0);
    // Get the current time after executing your code
    auto end_time = chrono::high_resolution_clock::now();

    // Calculate the duration of execution
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    // Output the duration in microseconds
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    return 0;
}
