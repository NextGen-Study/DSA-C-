#include <iostream>
#include <vector>;
using namespace std;


// Function to merge two halves of an array
void merge(int arr[], int start, int mid, int end) {
   vector<int> temp;

   int i = start;
   int j = mid + 1;

   while (i <= mid && j <= end) {
       if (arr[i] < arr[j]) {
           temp.push_back(arr[i]);
           i++;
       } else {
           temp.push_back(arr[j]);
           j++;
       }
   }

   while (i <= mid) {
       temp.push_back(arr[i]);
       i++;
   }

   while (j <= end) {
       temp.push_back(arr[j]);
       j++;
   }

   for(int idx = 0; idx < temp.size(); idx++) {
       arr[idx + start] = temp[idx];
   }

}

// Merge Sort function
void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2; // Avoids overflow

        // Recursively sort first and second halves
        
        //left half
        mergeSort(arr, start, mid);

        //right half
        mergeSort(arr, mid + 1, end);

        // Merge sorted halves
        merge(arr, start, mid, end);
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array:\n";
    printArray(arr, size);

    return 0;
}
