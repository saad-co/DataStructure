// code for merging the two max heaps
void heapify(vector<int>& arr, int i, int n)
{
    int largest = i;
    int leftChild = i * 2+1;
    int rightChild = leftChild + 1;

    if (leftChild < n && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }
     if (rightChild < n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest, n);
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    vector<int> ans;
    for(auto i:arr1)
    {
        ans.push_back(i);
    }
    for(auto j:arr2)
    {
        ans.push_back(j);
    }

    int size = ans.size();
    for(int i=(size/2)-1;i>=0;i--)
    {
        heapify(ans,i,size);
    }
    return ans;
}