#include<iostream>
#include<vector>

// #include <bits/stdc++.h>

void insertionSort(int n, std::vector<int>& arr) {
    if (n <= 1) {
        return;
    }

    insertionSort(n - 1, arr);

    int temp = arr[n - 1];
    int i = n - 2;
    for (; i >= 0; i--) {
        if (arr[i] > temp) {
            arr[i + 1] = arr[i];
        } else {
            break;
        }
    }
    arr[i + 1] = temp;
}

int main() {
    std::vector<int> arr = {3, 1, 2, 2};
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    insertionSort(arr.size(), arr);

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
