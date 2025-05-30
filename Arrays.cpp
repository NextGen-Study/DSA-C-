#include <iostream>
using namespace std;

 void printArray(int arr[], int size) {

        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getMax(int arr[], int size) {
        int max =arr[0];
        for(int i=0;i<size;i++)
        {
            if(arr[i] > max)
            {
              max = arr[i];
            }
        }
        return max;
    }

    int getMin(int arr[], int size) {
        int min =arr[0];
        for(int i=0;i<size;i++)
        {
            if(arr[i] < min)
            {
              min = arr[i];
            }
        }
        return min;

    }


int main()
{
    cout << "Introduction to arrays" << endl;

    //Declaring the array
     int arr[5] = {0};
     int arr1[5] = {1000,22,300,44,5};
     int arr2[5] = {};
     int arr3[] = {1,2,3,4,5};

    // printArray(arr, 5);

    // accessing the array
    // cout << arr[0] << endl;
    // cout << arr[1] << endl;
    // cout << arr[2] << endl;
    // cout << arr[3] << endl;
    // cout << arr[4] << endl;



    //Finding the size of array

    // cout << "Size of array is " << sizeof(arr)/sizeof(int) << endl;
    
    
    //Min Max

    // cout << "Max is " << getMax(arr1, 5) << endl;
    // cout << "Min is " << getMin(arr1, 5) << endl;
    
    
    int a = 10;

    cout << a << endl;
    
    return 0;

}
