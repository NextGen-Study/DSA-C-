#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(vector<int> preorder) {
static int index = -1;
    index++;
    if (preorder[index] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[index]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void preorderT(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorderT(root->left);
    preorderT(root->right);
}


int main()
{
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,-1};

  

    Node* root = buildTree(preorder);

    //   cout << root->data << endl;

    preorderT(root);
    return 0;
}