#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void traversal(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    traversal(root->left);
    traversal(root->right);
}

bool checkIsFullTree(Node* root){
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    if(root->left != NULL && root->right != NULL){
        return (checkIsFullTree(root->left) && checkIsFullTree(root->right));
    }
    return false;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    traversal(root);
    cout<<endl;
    if(checkIsFullTree(root)){
        cout<< "This is full binary tree";     
    }
    return 0;
}