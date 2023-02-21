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
    else{
        node_i->right = insert(node_i->right,x);
    }
}

void printNode(node *node_p){
    if(node_p != NULL){
        printNode(node_p->left);
        cout<<node_p->data<<" ";
        printNode(node_p->right);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n]={};
    node *myNode = NULL;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        myNode=insert(myNode,arr[i]);
    }
    printNode(myNode);
    return 0;
}