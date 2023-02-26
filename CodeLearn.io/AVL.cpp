// 7
// 1 2 3 4 5 6 7
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

int treeLevel(node *t){
	if (t == NULL) return -1;
	return 1 + max(treeLevel(t->left), treeLevel(t->right));
}

bool checkAvl(node *t){
	if (t == NULL) 	return true;
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return false;
	return checkAvl(t->left) && checkAvl(t->right);
}

void printTree(node *node_p){
    if(node_p != NULL){
        printTree(node_p->left);
        printTree(node_p->right);
        cout<<node_p->data<<" ";
        
    }
}

node *rotationRight(node *node_r){
    //cout<<node_r<<endl;
    node *A = node_r;
    node *B = node_r->left;
    node *D = B->right;
    node_r = B;
    B->right = A;
    A->left = D;
    return node_r;
}

node *rotationLeft(node *node_r){

    node *A = node_r;
    node *B = node_r->right;
    node *D = B->left;
    cout<<"Node A"<<A->data<<endl;
    cout<<"Node B"<<B->data<<endl;
    cout<<"Node D"<<D<<endl;
    node_r = B;
    B->left = A;
    A->right = D;
    cout<<"Node_root"<<node_r->data<<endl;
    cout<<"Node_l"<<node_r->left->data<<endl;
    cout<<"Node_r"<<node_r->right->data<<endl;
    cout<<"A right"<<node_r->left->right<<endl;
    return node_r;
}

int main(){
    int arr[7]={1,2,3,4,5,6,7};
    node *myNode = NULL;
    for(int i=0; i<7; i++){
        myNode = insert(myNode,arr[i]);
    }
    cout<<"root"<<myNode->data<<endl;
    printTree(myNode);
    cout<<endl;
    while(abs(treeLevel(myNode->left) - treeLevel(myNode->right)) > 1){
        if(treeLevel(myNode->right)>treeLevel(myNode->left)){
            cout<<"left"<<endl;
                myNode = rotationLeft(myNode);
                
                printTree(myNode);
                cout<<endl;
        }
        else{
            myNode = rotationRight(myNode);
                cout<<"right"<<endl;
                printTree(myNode);
                cout<<endl;
        }
    }
    printTree(myNode);
    return 0;
}