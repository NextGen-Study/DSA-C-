#include <iostream>
#define SIZE 5 // Define the size of the circular queue

using namespace std;

// Declare circular queue and front/rear pointers
int bnayihuique[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
bool isFull() {
    return ((rear + 1) % SIZE == front);
}

// Function to check if the queue is empty
bool isEmpty() {
    return (front == -1);
}

// Function to insert an element in the circular queue
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full! Cannot insert " << value << endl;
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    bnayihuique[rear] = value;
    cout << "Inserted " << value << endl;
}

// Function to remove an element from the circular queue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot dequeue." << endl;
        return;
    }

    cout << "Deleted " << bnayihuique[front] << endl;

    if (front == rear) {
        // Queue has only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Function to display the elements of the circular queue
void display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << bnayihuique[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

// Main function to test the circular queue
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); // Queue becomes full here

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70); // Elements wrap around


    enqueue(40);

    display();

    return 0;
}