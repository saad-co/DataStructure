#include <iostream>
using namespace std;

void rowMajorND(int dim)
{
    if (dim < 1)
    {
        throw runtime_error("enter more than 0 dimensions");
    }
    for (int i = 1; i <= dim; i++)
    {
        cout << "i" << i << ' ';
        for (int j = i + 1; j <= dim; j++)
        {
            cout << "D" << j << ' ';
        }
        if (i != dim)
        {
            cout << " + ";  
        }
    }
}

int main()
{
    int dim;
    cout << "Enter dimensions: ";
    cin >> dim;
    try
    {
        rowMajorND(dim);
    }
    catch (const exception& e)
    {
        cerr << e.what() << '\n';
    }
    return 0;
}