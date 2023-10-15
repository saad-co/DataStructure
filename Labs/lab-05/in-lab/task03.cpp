#include <iostream>

using namespace std;

class TwoDArray
{
private:
    int rows, cols;
    int *data;

    int getIndex(int i, int j) const
    {
        return j * rows + i;
    }

public:
    TwoDArray(int rows, int cols) : rows(rows), cols(cols)
    {
        data = new int[rows * cols]();
    }

    ~TwoDArray()
    {
        delete[] data;
    }

    TwoDArray(const TwoDArray &other) : rows(other.rows), cols(other.cols)
    {
        data = new int[rows * cols];
        copy(other.data, other.data + rows * cols, data);
    }

    int getIndexValue(int i, int j) const
    {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
        {
            return data[getIndex(i, j)];
        }
        else
        {
            throw out_of_range("Invalid indices");
        }
    }

    void setIndexValue(int i, int j, int val)
    {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
        {
            data[getIndex(i, j)] = val;
        }
        else
        {
            throw out_of_range("Invalid indices");
        }
    }

    void printArray() const
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << getIndexValue(i, j) << " ";
            }
            cout << endl;
        }
    }

    int addressOfIndex(int i, int j, int startIndex) const
    {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
        {
            return startIndex + getIndex(i, j);
        }
        else
        {
            throw out_of_range("Invalid indices");
        }
    }

    TwoDArray operator+(const TwoDArray &other) const
    {
        if (rows == other.rows && cols == other.cols)
        {
            TwoDArray result(rows, cols);
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    result.setIndexValue(i, j, getIndexValue(i, j) + other.getIndexValue(i, j));
                }
            }
            return result;
        }
        else
        {
            throw invalid_argument("Arrays must have the same dimensions for addition");
        }
    }

    void printSubArray(int r1, int r2, int c1, int c2) const
    {
        for (int i = r1; i <= r2; ++i)
        {
            for (int j = c1; j <= c2; ++j)
            {
                cout << getIndexValue(i, j) << " ";
            }
            cout << endl;
        }
    }

    void clear(int startRow, int endRow, int startCol, int endCol)
    {
        if (startRow >= 0 && startRow < rows && endRow >= startRow && endRow < rows &&
            startCol >= 0 && startCol < cols && endCol >= startCol && endCol < cols)
        {
            for (int i = startRow; i <= endRow; ++i)
            {
                for (int j = startCol; j <= endCol; ++j)
                {
                    setIndexValue(i, j, 0);
                }
            }
        }
        else
        {
            throw std::out_of_range("Invalid indices");
        }
    }
};

int main()
{
    TwoDArray array1(3, 3);
    array1.setIndexValue(0, 0, 1);
    array1.setIndexValue(0, 1, 2);
    array1.setIndexValue(1, 0, 3);
    array1.setIndexValue(2, 2, 4);

    TwoDArray array2(3, 3);
    array2.setIndexValue(0, 0, 5);
    array2.setIndexValue(1, 1, 6);
    array2.setIndexValue(2, 2, 7);

    cout << "Array 1:" << endl;
    array1.printArray();

    cout << "Array 2:" << endl;
    array2.printArray();

    TwoDArray array3 = array1 + array2;
    cout << "Array 3 (Result of Addition):" << endl;
    array3.printArray();

    cout << "Subarray of Array 1:" << endl;
    array1.printSubArray(0, 1, 0, 1);

    cout<<"clearing the array: "<<endl;
    array2.clear(0, 1, 0, 1);
    array2.printArray();

    return 0;
}