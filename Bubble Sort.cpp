#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}
void printArray(int arr[], int size){

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[5] = {100,500,300,400,200};
    bubbleSort(arr, 5);
    printArray(arr, 5);
    return 0;
}