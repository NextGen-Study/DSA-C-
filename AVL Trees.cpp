#include <iostream>
using namespace std;

// Node definition
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        key = val;
        left = right = nullptr;
        height = 1;
    }
};

// Utility: get height of node
int getHeight(Node* node) {
    if (!node) return 0;
    return node->height;
}

// Utility: get balance factor
int getBalance(Node* node) {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Utility: update height
void updateHeight(Node* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Right rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x; // new root
}

// Left rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y; // new root
}

// Insert into AVL tree
Node* insert(Node* root, int key) {
    // Normal BST insert
    if (!root) return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // No duplicates

    // Update height
    updateHeight(root);

    // Check balance
    int balance = getBalance(root);

    // 4 Rotation Cases
    // Left Left
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Right Right
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Left Right
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // unchanged
}

// In-order traversal
void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

// Driver
int main() {
    Node* root = nullptr; //Starts with an Empty Tree

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "In-order Traversal of AVL Tree: ";
    inOrder(root);
    cout << endl;

    return 0;
}
