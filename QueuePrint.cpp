#include<queue>
#include<iostream>
using namespace std;

void generateBinary(int N) {
    queue<string> q;
    q.push("1");

    for (int i = 0; i < N; i++) {
        string front = q.front();
        q.pop();

        cout << front << " ";
        q.push(front + "0");
        q.push(front + "1");
    }
}

int main()
{
cout << "Enter the Number";
int N;
cin >> N;
generateBinary(N);
}