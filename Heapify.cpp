#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
int largest = i;
int left = 2*i;
int right = 2*i+1;


if(left <= n && arr[left] > arr[largest])
{
    largest = left;
}

if(right <= n && arr[right] > arr[largest])
{
    largest = right;
}

if(largest != i)
{
    swap(arr[i],arr[largest]);
    heapify(arr,n,largest);
}

}

void buildHeap(int arr[],int n)
{
    for(int i = n/2; i>=1; i--)
    {
     heapify(arr,n,i);
    }
}

void printHeap(int arr[],int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    
}
int main()
{
    int arr[] ={0,53,52,55,30,20};

    int n = 5;

    buildHeap(arr,n);

    cout << "Array after heapify: ";

    printHeap(arr,n);

    return 0;
}