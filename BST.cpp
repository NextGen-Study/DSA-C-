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

    cout << root-> data << endl;


    inorder(root);
    return 0;
}