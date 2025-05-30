#include<iostream>
using namespace std;
int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    // int mid = s + (e - s) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
        // mid = s + (e - s) / 2;
    }
    return -1;

}
int main(){

    int arr[5] = {1,2,3,4,5};
    int key = 30;
    cout << binarySearch(arr, 5, key) << endl;
    return 0;

}