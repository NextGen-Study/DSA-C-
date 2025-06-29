#include<iostream>
#include <queue>
using namespace std;

void print(priority_queue<int , vector<int>, greater<int>> q)
{
    for(int i=0;i<5;i++)
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main()
{

    priority_queue<int> Maxheap;

    Maxheap.push(30);
    Maxheap.push(60);
    Maxheap.push(70);
    Maxheap.push(10);
    Maxheap.push(25);

    cout << "The MaxHeap is : ";
    // print(Maxheap);

    priority_queue<int , vector<int>, greater<int>> Minheap;

    Minheap.push(30);
    Minheap.push(60);
    Minheap.push(70);
    Minheap.push(10);
    Minheap.push(25);

    cout << "The MinHeap is : ";
    print(Minheap);




    return 0;

}