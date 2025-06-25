#include <iostream>
#include <vector>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};


node* findMin(node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

node* deleteNode(node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: One child
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        node* temp = findMin(root->right); // inorder successor
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

node* insert(node* root, int val){
    if (root == NULL){
        return new node(val);
    }
    if (root->data > val){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

node* buildBST(vector<int> arr){

    node* root = NULL;

    for(int val : arr){
        root = insert(root, val);
    }
    
    return root;
}

void inorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){

    vector<int> arr = {3,2,1,5,6,4};

    node* root = buildBST(arr);

    cout << "Root: " << root->data << endl;

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 5); // example: delete node with value 5

    cout << "Inorder after deleting 5: ";
    inorder(root);
    cout << endl;

    return 0;
}

