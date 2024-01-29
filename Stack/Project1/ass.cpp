#include <iostream>
using namespace std;

template <class T>
class NDArray
{
	T* data;
	int noOfDimensions;
	int* sizeOfDimensions;
	int* startingIndex;
	int getRowMajorIndexMapping(int* arr) const
	{
		if (isIndexBoundsValid(arr))
		{
			int* temp = new int[noOfDimensions];
			for (int i = 0; i < noOfDimensions; i++)
			{
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
	NDArray(const int* arr1, const int* arr2, int size1, int size2)
	{
		noOfDimensions = size1;
		sizeOfDimensions = new T[size1];
		startingIndex = new T[size1];
		if (size1 == 0 && size2 == 0)
		{
			cout << "L py char: " << endl;
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
	NDArray(const NDArray<T>& obj) // copy constructor
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
	NDArray<T>& operator=(const NDArray<T>& rhs) // copy all the elements of parameter array into an array and then return it
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
	bool isIndexBoundsValid(const T* arr) const
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
	T& operator()(int* arr)
	{
		int indx = getRowMajorIndexMapping(arr);
		return data[indx];
	}
	const int& operator()(int* list) const
	{
		int indx = getRowMajorIndexMapping(list);
		return data[indx];
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

void samplerun1()
{
	const int arr1[2] = { 2, 4 };
	const int arr2[2] = { 5, -1 };
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
			int a[2] = { i, j };
			cin >> b(a);
		}
	}
	for (int i = b.getDimensionLowerIndex(0); i <= b.getDimensionHigherIndex(0); i++)
	{
		for (int j = b.getDimensionLowerIndex(1); j <= b.getDimensionHigherIndex(1); j++)
		{
			int arr[2] = { i, j };
			cout << b(arr) << '\t';
		}
		cout << '\n';
	}
}

int main()
{
	const int arr1[2] = { 2, 4 };
	const int arr2[2] = { 5, -1 };
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
			int a[2] = { i, j };
			cin >> b(a);
		}
	}
	for (int i = b.getDimensionLowerIndex(0); i <= b.getDimensionHigherIndex(0); i++)
	{
		for (int j = b.getDimensionLowerIndex(1); j <= b.getDimensionHigherIndex(1); j++)
		{
			int arr[2] = { i, j };
			cout << b(arr) << '\t';
		}
		cout << '\n';
	}

	return 0;
}