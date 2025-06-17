#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function: places pivot at correct position
int partition(int arr[], int start, int end) {
    int pivot = arr[end]; // Choosing the last element as pivot
    int i = start - 1;        // Index of smaller element

    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;            // Move smaller element to left
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]); // Place pivot in correct position
    return i + 1;
}

// Quick Sort function (recursive)
void quickSort(int arr[], int start, int end) {
    if (start < end) {
      
        // pi is partitioning index
        int pi = partition(arr, start, end);

        // Recursively sort left and right parts
        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Sorted array:\n";
    printArray(arr, size);

    return 0;
}
