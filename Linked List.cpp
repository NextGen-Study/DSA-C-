#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Insert at head
void insertAtHead(Node*& head, int value) {
    Node* temp = new Node(value);
    temp->next = head;
    head = temp;
}

// Insert at tail
void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display the linked list
void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Main function
int main() {
    Node* head = new Node(0);
    cout << "Linked List: ";
    display(head);

    insertAtHead(head, 10);   // List: 10
    insertAtHead(head, 20);   // List: 20 -> 10
    insertAtTail(head, 30);   // List: 20 -> 10 -> 30
    insertAtTail(head, 40);   // List: 20 -> 10 -> 30 -> 40

    cout << "Linked List: ";
    display(head);

    return 0;
}
