#include <iostream>
#include <cstdlib> // For rand() and srand() functions
#include <ctime>   // For time() function

using namespace std;

void allocateArray(int*** arr, int n = 3);
void initializeArray(int*** arr, int n = 3);
void printArray(int*** arr, int n = 3);
void deallocateArray(int*** arr, int n = 3);

int main() {
    int*** arr = nullptr;
    allocateArray(arr);
    initializeArray(arr);
    printArray(arr);
    deallocateArray(arr);
    return 0;
}

void allocateArray(int*** &arr, int n) {
    arr = new int**[n];
    for (int i = 0; i < n; ++i) {
        *(arr+i) = new int*[n];
        for (int j = 0; j < n; ++j) {
            *(*(arr+i)+j)= new int[n];
        }
    }
}

void initializeArray(int*** &arr, int n) {
    // Seed for random number generation
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                (*arr)[i][j][k] = rand() % 100; // Initialize with random integers between 0 and 99
            }
        }
    }
}

void printArray(int*** arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cout << "arr[" << i << "][" << j << "][" << k << "] = " << (*arr)[i][j][k] << endl;
            }
        }
    }
}

void deallocateArray(int*** arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            delete[] *(*(arr+i)+j);
        }
        delete[] (*arr)[i];
    }
    delete[] (*arr);
    *arr = nullptr; // Reset the pointer to nullptr to avoid dangling pointer
}
