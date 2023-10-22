#include<bits/stdc++.h>

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
    if(root == NULL){
        return;
    }    
    traversal(root->left);
    traversal(root->right);
    cout<<root->data<<" ";
}

Node* insert(Node* root, int data){
    if(root == NULL) return new Node(data);
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

int main()
{
    Node* root = new Node(8);
    insert(root, 3);
    insert(root, 6);
    insert(root, 4);
    insert(root, 4);
    insert(root, 1);
    insert(root, 7);
    insert(root, 10);
    insert(root, 14);
    
    traversal(root);
    return 0;
