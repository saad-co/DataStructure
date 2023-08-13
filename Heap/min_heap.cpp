#include <iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr, int i, int n) {
   int smallest = i;
  int leftChild = 2 * i + 1; // Calculate the index of the left child
  int rightChild = 2 * i + 2; // Calculate the index of the right child

  if (leftChild < n && arr[leftChild] < arr[smallest]) {
    smallest = leftChild;
  }
  if (rightChild < n && arr[rightChild] < arr[smallest]) {
    smallest = rightChild;
  }

  if (smallest != i) {
    swap(arr[i], arr[smallest]);
    heapify(arr, smallest, n);
  }
}
vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();
  for (int i = (n / 2)-1; i >= 0; i--) {
    heapify(arr, i, n);
  }

  return arr;
}



int main()
{
    vector<int> arr = {9, 3 ,2 ,6 ,7};
    buildMinHeap(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" "; 
    }cout<<endl;
    return 0;
}
