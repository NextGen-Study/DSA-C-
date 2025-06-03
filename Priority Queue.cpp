#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int> q;

    q.push(10);
    q.push(50);
    q.push(30);
    q.push(20);
    q.push(40);


    int n  = q.size();

    for(int i = 0; i < n ; i++)
    {
        cout << q.top() << " ";
        q.pop();
    }

    return 0;
}