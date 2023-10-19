#include <iostream>
using namespace std;
int leaf = 0;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

int depthOfTree(Node* root){
    int d = 0;
    while(root != NULL){
        d += 1;
        root = root->left;
    }
    return d;
}

// method 1:
bool checkIsPerfect(Node* root, int d, int level){
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL){
        return (d == level+1);
    }
    if(root->left == NULL || root->right == NULL) return false;
    return(checkIsPerfect(root->left, d, level+1) && checkIsPerfect(root->right, d, level+1));
}

//method 2
// void traversal(Node* root){
//     if(root == NULL) return;
//     if(root->left == NULL && root->right == NULL) leaf++;
//     traversal(root->left);
//     traversal(root->right);
// }

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //cout<< depthOfTree(root)<<endl;
    //traversal(root);
    //cout<<leaf;
    if(checkIsPerfect(root, depthOfTree(root), 0)) cout<<"This is perfect tree";
    return 0;
}