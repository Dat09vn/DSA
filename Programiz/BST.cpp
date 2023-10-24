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

Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* delete_node(Node* root, int data){
    if(root == NULL) return NULL;
    if(data < root->data){
        root->left = delete_node(root->left, data);
    }
    else if(data > root->data){
        root->right = delete_node(root->right, data);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

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
    delete_node(root, 3);
    cout<<endl;
    traversal(root);

    return 0;
}
