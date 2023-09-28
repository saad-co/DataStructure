#include <iostream>

using namespace std;

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
    for(int i=0;i<sizee;i++)
    {
        arr[i] = rand()%10;
    }
    for(int i=0;i<sizee;i++)
    {
        cout<<arr[i]<<" ";
    }
}