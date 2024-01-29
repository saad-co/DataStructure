#include <iostream>
using namespace std;

template <class T>
class NDArray
{
    T *data;
    int noOfDimensions;
    int *sizeOfDimensions;
    int *startingIndex;
    int getRowMajorIndexMapping(int *arr) const
    {
        if (isIndexBoundsValid(arr))
        {
            int *temp = new int[noOfDimensions];
            for (int i = 0; i < noOfDimensions; i++)
            {
                0
                temp[i] = arr[i] - startingIndex[i];
            }

            int indx = 0;
            for (int i = 0; i < noOfDimensions; i++)
            {
                int product = 1;
                for (int j = i + 1; j < noOfDimensions; j++)
                {
                    product *= sizeOfDimensions[j];
                }
                indx += product * temp[i];
            }
            delete[] temp;
            return indx;
        }
        else
        {
            cout << "Invalid index bounds" << endl;
            return -1; // Indicate an error
        }
    }

public:
    NDArray(const int *arr1, const int *arr2, int size1, int size2)
    {
        noOfDimensions = size1;
        sizeOfDimensions = new T[size1];
        startingIndex = new T[size1];
        if (size1 == 0 && size2 == 0)
        {
            cout << " " << endl;
        }
        else if (size1 > size2)
        {
            sizeOfDimensions = new T[size1];
            noOfDimensions = size1;
            startingIndex = new T[size1];
            for (int i = 0; i < size1; i++)
            {
                sizeOfDimensions[i] = arr1[i];
            }
            for (int k = 0; k < size2; k++)
            {
                startingIndex[k] = arr2[k];
            }
            for (int j = size2; j < size1; j++)
            {
                startingIndex[j] = 0;
            }
        }
        else if (size2 >= size1)
        {
            sizeOfDimensions = new T[size1];
            noOfDimensions = size1;
            for (int i = 0; i < size1; i++)
            {
                sizeOfDimensions[i] = arr1[i];
            }
            for (int j = 0; j < size1; j++)
            {
                startingIndex[j] = arr2[j];
            }
        }
        int totalSize = 1;
        for (int i = 0; i < noOfDimensions; i++)
        {
            totalSize *= sizeOfDimensions[i];
        }
        data = new T[totalSize];
    }
    NDArray(const NDArray<T> &obj) // copy constructor
    {
        noOfDimensions = obj.noOfDimensions;
        if (noOfDimensions != 0)
        {
            sizeOfDimensions = new int[noOfDimensions];
            for (int i = 0; i < noOfDimensions; i++)
            {
                sizeOfDimensions[i] = obj.sizeOfDimensions[i];
            }
            startingIndex = new int[noOfDimensions];
            for (int i = 0; i < noOfDimensions; i++)
            {
                startingIndex[i] = obj.startingIndex[i];
            }
            int totalSize = 1;
            for (int i = 0; i < noOfDimensions; i++)
            {
                totalSize *= sizeOfDimensions[i];
            }
            data = new T[totalSize];
            for (int i = 0; i < noOfDimensions; i++)
            {
                data[i] = obj.data[i];
            }
        }
    }
    NDArray<T> &operator=(const NDArray<T> &rhs) // copy all the elements of parameter array into an array and then return it
    {
        if (this != &rhs)
        {
            if (sizeOfDimensions != nullptr)
            {
                delete[] sizeOfDimensions;
                sizeOfDimensions = nullptr;
            }
            if (startingIndex != nullptr)
            {
                delete[] startingIndex;
                startingIndex = nullptr;
            }
            if (data != nullptr)
            {
                delete[] data;
                data = nullptr;
            }
            noOfDimensions = rhs.noOfDimensions;
            if (noOfDimensions != 0)
            {
                sizeOfDimensions = new int[noOfDimensions];
                for (int i = 0; i < noOfDimensions; i++)
                {
                    sizeOfDimensions[i] = rhs.sizeOfDimensions[i];
                }
                startingIndex = new int[noOfDimensions];
                for (int i = 0; i < noOfDimensions; i++)
                {
                    startingIndex[i] = rhs.startingIndex[i];
                }
                int totalSize = 1;
                for (int i = 0; i < noOfDimensions; i++)
                {
                    totalSize *= sizeOfDimensions[i];
                }
                data = new int[totalSize];
                for (int i = 0; i < noOfDimensions; i++)
                {
                    data[i] = rhs.data[i];
                }
            }
        }
        return *this;
    }
    int getNumberOfDimensions() const
    {
        return noOfDimensions;
    }
    int getDimensionSize(const int d) const
    {
        if (d >= 0 && d < noOfDimensions)
        {
            return sizeOfDimensions[d];
        }
        else
        {
            cout << "Invalid Dimension" << endl;
            return -1;
        }
    }
    int getDimensionLowerIndex(const int d) const
    {
        if (d >= 0 && d < noOfDimensions)
        {
            return startingIndex[d];
        }
        else
        {
            cout << "Invalid Dimension" << endl;

            return -1;
        }
    }
    int getDimensionHigherIndex(const int d) const
    {
        if (d >= 0 && d < noOfDimensions)
        {
            return ((startingIndex[d] + sizeOfDimensions[d]) - 1);
        }
        else
        {
            cout << "Invalid Dimension" << endl;
            return -1;
        }
    }
    bool isIndexBoundsValid(const T *arr) const
    {
        for (int i = 0; i < noOfDimensions; i++)
        {
            if (arr[i] < startingIndex[i] || arr[i] >= (startingIndex[i] + sizeOfDimensions[i]))
            {
                return false;
            }
        }
        return true;
    }
    T &operator()(int *arr)
    {
        int indx = getRowMajorIndexMapping(arr);
        return data[indx];
    }
    const int &operator()(int *list) const
    {
        int indx = getRowMajorIndexMapping(list);
        return data[indx];
    }
    void printArray()
    {
        for (int i = 0; i < noOfDimensions; i++)
        {
            int indx = getRowMajorIndexMapping(startingIndex);
            cout << data[indx] << " ";
        }
        cout << endl;
    }
    ~NDArray()
    {
        if (sizeOfDimensions != nullptr)
        {
            delete[] sizeOfDimensions;
            sizeOfDimensions = nullptr;
        }
        if (startingIndex != nullptr)
        {
            delete[] startingIndex;
            startingIndex = nullptr;
        }
        if (data != nullptr)
        {
            delete[] data;
            data = nullptr;
        }
    }
};

void sampleRun1()
{
    const int arr1[2] = {2, 4};
    const int arr2[2] = {5, -1};
    NDArray<int> b(arr1, arr2, 2, 2);
    cout << "Number of Dimensions: " << b.getNumberOfDimensions() << "\n";
    for (int i = 0; i < b.getNumberOfDimensions(); i++)
    {
        cout << "Dim # " << i << " size= " << b.getDimensionSize(i) << " Index Range=(" << b.getDimensionLowerIndex(i) << " ~" << b.getDimensionHigherIndex(i) << ") " << endl;
    }
    for (int i = b.getDimensionLowerIndex(0); i <= b.getDimensionHigherIndex(0); i++)
    {
        for (int j = b.getDimensionLowerIndex(1); j <= b.getDimensionHigherIndex(1); j++)
        {
            cout << "[" << i << ":" << j << "]= ";
            int a[2] = {i, j};
            cin >> b(a);
        }
    }
    for (int i = b.getDimensionLowerIndex(0); i <= b.getDimensionHigherIndex(0); i++)
    {
        for (int j = b.getDimensionLowerIndex(1); j <= b.getDimensionHigherIndex(1); j++)
        {
            int arr[2] = {i, j};
            cout << b(arr) << '\t';
        }
        cout << '\n';
    }
}

void sampleRun2()
{
    int list1[2] = {2, 4};
    int list2[2] = {5, -1};
    NDArray<int> b(list1, nullptr, 2, 0);
    cout << "Number of Dimensions: " << b.getNumberOfDimensions() << "\n";
    for (int i = 0; i < b.getNumberOfDimensions(); i++)
    {
        cout << "Dim # " << i << " size= " << b.getDimensionSize(i) << " Index Range= (" << b.getDimensionLowerIndex(i) << " ~ " << b.getDimensionHigherIndex(i) << ")" << endl;
    }
}

void sampleRun3()
{
    int list1[] = {2, 4};
    int list2[] = {-3, 2};
    NDArray<int> b(list1, list2, 2, 2);
    int arr[2] = {1, 2};
    b(arr) = 78; // terminates the application because first index # is invalid
}

void sampleRun4()
{
    int list1[] = {2, 4, 3};
    int list2[] = {2, 7};
    NDArray<int> b(list1, list2, 3, 2);
    cout << "Number of Dimensions: " << b.getNumberOfDimensions() << "\n";
    for (int i = 0; i < b.getNumberOfDimensions(); i++)
    {
        cout << "Dim # " << i << " size= " << b.getDimensionSize(i) << " Index Range= (" << b.getDimensionLowerIndex(i) << " ~ " << b.getDimensionHigherIndex(i) << ")" << endl;
    }
}

void sampleRun5()
{
    int list1[] = {2, 4};
    int list2[] = {2, 7, 9};
    NDArray<int> b(list1, list2, 2, 3);
    cout << "Number of Dimensions: " << b.getNumberOfDimensions() << "\n";
    for (int i = 0; i < b.getNumberOfDimensions(); i++)
    {
        cout << "Dim # " << i << " size= " << b.getDimensionSize(i) << " Index Range= (" << b.getDimensionLowerIndex(i) << " ~ " << b.getDimensionHigherIndex(i) << ")" << endl;
    }
}

void sampleRun6()
{
    int list1[] = {5};
    NDArray<int> a(list1, nullptr, 1, 0);
    for (int i = a.getDimensionLowerIndex(0); i <= a.getDimensionHigherIndex(0); i++)
    {
        cout << '[' << i << "]: ";
        int arr[1] = {i};
        cin >> a(arr);
    }
    for (int i = a.getDimensionLowerIndex(0); i <= a.getDimensionHigherIndex(0); i++)
    {
        int arr[1] = {i};
        cout << a(arr) << ',';
    }
}

int main()
{
    cout << "\n--------------------SAMPLE RUN 1--------------------" << endl
         << endl;
    sampleRun1();

    cout << "\n--------------------SAMPLE RUN 2--------------------" << endl
         << endl;
    sampleRun2();

    cout << "\n--------------------SAMPLE RUN 3--------------------" << endl
         << endl;
    sampleRun3();

    cout << "\n--------------------SAMPLE RUN 4--------------------" << endl
         << endl;
    sampleRun4();

    cout << "\n--------------------SAMPLE RUN 5--------------------" << endl
         << endl;
    sampleRun5();

    cout << "\n--------------------SAMPLE RUN 6--------------------" << endl
         << endl;
    sampleRun6();
    cout << endl
         << endl;
    int size1, size2;

    cout << "\n--------------------Create N-D Array--------------------" << endl
         << endl
         << endl;
    cout << "Enter the size of dimensions for the NDArray: ";
    cin >> size1;
    while (size1 < 0)
    {
        cout << "Invalid dimension size. Please enter a positive integer." << endl;
        cin >> size1;
    }

    int *arr1 = new int[size1];
    int *arr2 = new int[size1];
    cout << "Enter the size of starting indices for the NDArray: ";
    cin >> size2;
    while (size2 < 0)
    {
        cout << "Invalid dimension size. Please enter a positive integer." << endl;
        cin >> size2;
    }

    cout << "Enter the dimensions for the NDArray: ";
    for (int i = 0; i < size1; i++)
    {
        cin >> arr1[i];
        if (arr1[i] < 0)
        {
            cout << "Invalid dimension size. Please enter a positive integer." << endl;
            i--;
        }
    }

    cout << "Enter the starting indices for the NDArray: ";
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }

    NDArray<int> myArray(arr1, arr2, size1, size2);

    int choice;
    do
    {
        cout << "\nNDArray Operations Menu:" << endl;
        cout << "1. Get number of dimensions" << endl;
        cout << "2. Get dimension size" << endl;
        cout << "3. Get dimension lower index" << endl;
        cout << "4. Get dimension higher index" << endl;
        cout << "5. Check index bounds validity" << endl;
        cout << "6. Access element using indices" << endl;
        cout << "7. Fill array values from user input" << endl;
        cout << "8. Print array values: " << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Number of dimensions: " << myArray.getNumberOfDimensions() << endl;
            break;
        case 2:
            int dim;
            cout << "Enter the dimension index: ";
            cin >> dim;
            cout << "Dimension size: " << myArray.getDimensionSize(dim) << endl;
            break;
        case 3:
            cout << "Enter the dimension index: ";
            cin >> dim;
            cout << "Dimension lower index: " << myArray.getDimensionLowerIndex(dim) << endl;
            break;
        case 4:
            cout << "Enter the dimension index: ";
            cin >> dim;
            cout << "Dimension higher index: " << myArray.getDimensionHigherIndex(dim) << endl;
            break;
        case 5:
        {
            int *indices = new int[size1];
            cout << "Enter the indices to check validity: ";
            for (int i = 0; i < size1; i++)
            {
                cin >> indices[i];
            }
            cout << "Index bounds validity: " << (myArray.isIndexBoundsValid(indices) ? "Valid" : "Invalid") << endl;
            delete[] indices;
            break;
        }
        case 6:
        {
            int *indices = new int[size1];
            cout << "Enter the indices to access the element: ";
            for (int i = 0; i < size1; i++)
            {
                cin >> indices[i];
            }
            cout << "Element at indices: " << myArray(indices) << endl;
            delete[] indices;
            break;
        }
        case 7: 
        {
            for (int i = myArray.getDimensionLowerIndex(0); i <= myArray.getDimensionHigherIndex(0); i++)
            {
                for (int j = myArray.getDimensionLowerIndex(1); j <= myArray.getDimensionHigherIndex(1); j++)
                {
                    int indices[2] = {i, j};
                    cout << "Enter value for [" << i << ":" << j << "]: ";
                    cin >> myArray(indices);
                }
            }
            cout << "Array values filled successfully." << endl;
            break;
        }
        case 8: 
        {
            for (int i = myArray.getDimensionLowerIndex(0); i <= myArray.getDimensionHigherIndex(0); i++)
            {
                for (int j = myArray.getDimensionLowerIndex(1); j <= myArray.getDimensionHigherIndex(1); j++)
                {
                    int indices[2] = {i, j};
                    cout << myArray(indices) << " ";
                }
            }
            break;
        }
        case 0:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);
    delete[] arr1;
    delete[] arr2;
    return 0;
}