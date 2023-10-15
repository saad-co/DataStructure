#include<iostream>
using namespace std;

int my_algo(int arr[], int n, int temp_arr[])
{
    int maximum = 0;
    int temp_max = 0;
    int start = 0;
    int strt = 0; 

    for (int i = 0; i < n; i++)
    {
        temp_max = temp_max + arr[i];
        if (temp_max < 0) {
            temp_max = 0;
            start = i + 1; 
        }
        if (maximum < temp_max) {
            maximum = temp_max;
            strt = start;
            for (int j = strt; j <= i; j++) {
                temp_arr[j] = arr[j];
            }
        }
    }
    return strt;
}

int main()
{
    int arr[10] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    const int n = 10;
    int temp_arr[n] = {0};

    int indx = my_algo(arr, n, temp_arr);
    cout << "Maximum contiguous sum index starts from " << arr[indx] << endl;
    cout << "Maximum contiguous subarray: ";
    for (int i = indx; i < n && temp_arr[i] != 0; i++) {
        cout << temp_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
