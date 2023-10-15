#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

class Matrix
{
private:
    int row;
    int col;
    int **data;

public:
    int getRow() const
    {
        return row;
    }
    int getcol() const
    {
        return col;
    }
    Matrix(int numrow = 0, int numcol = 0)
    {
        row = numrow;
        col = numcol;
        data = new int *[row];
        for (int i = 0; i < row; i++)
            data[i] = new int[col];
    }
    ~Matrix()
    {
        if (data)
        {
            for (int i = 0; i < row; i++)
                delete[] data[i];
            delete[] data;
        }
    }
    void set(int i, int j, int val)
    {
        data[i][j] = val;
    }
    int get(int i, int j) const
    {
        return data[i][j];
    }
    void display() const
    {
        for (int i = 0; i < row; i++)
        {
            cout << endl;
            for (int j = 0; j < col; j++)
                cout << data[i][j] << " ";
        }
        cout << endl;
    }
    int *operator[](int idx) const
    {
        return data[idx];
    }
};

class sparseMatrix : public Matrix
{
private:
    int non_zeros;
    int rows;
    int cols;
    int *row;
    int *col;
    int *val;

public:
    sparseMatrix(int non_zero = 0, int r = 3, int c = 3) : non_zeros(non_zero), rows(r), cols(c)
    {
        row = new int[non_zero];
        col = new int[non_zero];
        val = new int[non_zero];
    }
    void Read_Sparse_Matrix(Matrix m)
    {
        int nz = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (m[i][j] != 0)
                {
                    nz++;
                }
            }
        }
        non_zeros = nz;
        row = new int[non_zeros];
        col = new int[non_zeros];
        val = new int[non_zeros];

        int count = 0;
        for (int i = 0; i < m.getRow(); i++)
        {
            for (int j = 0; j < m.getcol(); j++)
            {
                if (m[i][j] != 0)
                {
                    row[count] = i;
                    col[count] = j;
                    val[count] = m.get(i, j);
                    count++;
                }
            }
        }
    }
    void display() const
    {
        int count = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (count < non_zeros && i == row[count] && j == col[count])
                {
                    cout << val[count] << " ";
                    count++;
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << "\n";
        }
    }
};

int main()
{
    // int row, col;
    // cin >> row >> col;
    // Matrix m(row, col);
    // for (int i = 0; i < row; i++)
    //     for (int j = 0; j < col; j++)
    //     {
    //         int val = rand() % 100;
    //         m.set(i, j, val);
    //     }
    // m.display();
    // printRandomNumbersToFile(row, col);

    Matrix matrix1(3, 3);
    Matrix matrix2(3, 3);
    ifstream file1("file1.txt", ios::in);
    ifstream file2("file2.txt", ios::in);

    if (file1 && file2)
    {
        int val1 = 0, val2 = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                file1 >> val1;
                file2 >> val2;
                matrix1.set(i, j, val1);
                matrix2.set(i, j, val2);
            }
        }
    }
    else
    {
        cout << "Unable to open file: " << endl;
    }

    cout << "matrix1 data from file: " << endl;
    matrix1.display();
    cout << "matrix2 data from file: " << endl;
    matrix2.display();

    sparseMatrix s1;
    sparseMatrix s2;
    s1.Read_Sparse_Matrix(matrix1);
    s2.Read_Sparse_Matrix(matrix2);

    cout << "sparse matrix data :1" << endl;
    s1.display();

    cout << "sparse matrix data :2" << endl;
    s2.display();

    return 0;
}
