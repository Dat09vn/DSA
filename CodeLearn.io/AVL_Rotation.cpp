#include<iostream>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *insert(node *node_i, int x){
    if(node_i == NULL){
        node *temp = new node;
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else if(node_i->data > x){
        node_i->left = insert(node_i->left,x);
    }
    else {
        node_i->right = insert(node_i->right,x);
    }
}

void printTree(node *node_p){
    if(node_p != NULL){
        printTree(node_p->left);
        printTree(node_p->right);
        cout<<node_p->data<<" ";
        
    }
}
node *rotationRight(node *node_r){
    cout<<node_r<<endl;
    node *A = node_r;
    node *B = node_r->left;
    node *D = B->right;
    node_r = B;
    B->right = A;
    A->left = D;
    return node_r;
}

int main(){
    node *myNode = NULL;
    myNode = insert(myNode,8);
    myNode = insert(myNode,9);
    myNode = insert(myNode,4);
    myNode = insert(myNode,2);
    myNode = insert(myNode,6);
    myNode = insert(myNode,1);
    myNode = insert(myNode,3);
    myNode = insert(myNode,5);
    myNode = insert(myNode,7);
    printTree(myNode);
    myNode = rotationRight(myNode);
    printTree(myNode);
    return 0;
}