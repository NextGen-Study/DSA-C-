#include<iostream>
using namespace std;
void rowSum(int arr[3][3])
{
for(int i=0;i<3;i++)
{
    int sum=0;
    for(int j=0;j<3;j++)
    {
        sum+=arr[i][j];
    }
    cout<<sum<<" ";
}
}
void printArray(int arr[], int size){
    }
int main()
{
int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
rowSum(arr);
}