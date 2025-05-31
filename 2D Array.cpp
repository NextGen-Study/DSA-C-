#include<iostream>
using namespace std;
void printArrayRow(int arr[][3], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printArrayCols(int arr[][3], int rows, int cols){
   for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}
int main(){
int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
int arr1[3][3];
int arr2[][3] = {1,2,3,4,5,6,7,8,9};
//formula c x i + j

printArrayCols(arr, 3, 3);
return 0;
}