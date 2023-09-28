#include <iostream>
#include<algorithm>
using namespace std;

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

void fnBubbleSort(int Array[], unsigned int Size, int SortKey) {
    for (unsigned int i = 0; i < Size - 1; i++) {
        for (unsigned int j = 0; j < Size - i - 1; j++) {
            if ((SortKey == 0 && Array[j] > Array[j + 1]) ||
                (SortKey != 0 && Array[j] < Array[j + 1])) {
       
                int temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }
}


int main()
{
    const long long int sizee = 10;
    int arr[sizee];
    for(int i=0;i<sizee;i++)
    {
        arr[i] = rand()%10;
    }
    fnBubbleSort(arr,sizee,0);
    for(int i=0;i<sizee;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int res = arr[3];
    cout<<res<<endl;
    cout<<fnBinarySearch(arr,sizee,res);
    return 0;
}