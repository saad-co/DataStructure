#include <iostream>
using namespace std;
void heapify(int arr[], int i, int n)
{
    int largest = i;
    int leftChild = i * 2;
    int rightChild = leftChild + 1;

    if (leftChild <= n && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }
    if (rightChild <= n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (largest != i)
    { 
        swap(arr[largest], arr[i]);
        heapify(arr, largest, n);
    }
}

void heapSort(int *arr, int n)
{
    int size = n;
    while(size>1)
    {
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,1,size);
    }
    
}

int main()
{
    int arr[6] = {-1, 54,53,55,52,50};
    heapify(arr,1,5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;



    int n = 5;
    heapSort(arr, n);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; 
    return 0;
}