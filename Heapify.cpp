#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;           // Initialize largest as root
    int left = 2 * i;          // Left child
    int right = 2 * i + 1;     // Right child

    if (left <= n && arr[left] > arr[largest])
        largest = left;

    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }
}

void printHeap(int arr[], int n) {
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
   
    int arr[] = {0, 4, 10, 3, 5, 1}; 
    int n = 5;

    buildHeap(arr, n);

    cout << "Max Heap: ";
    printHeap(arr, n);

    return 0;
}
