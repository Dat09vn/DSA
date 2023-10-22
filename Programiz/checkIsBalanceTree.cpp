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

bool checkIsBalance(Node* root, int *height){
    int rightHeight = 0, leftHeight = 0;
    bool l = 0, r = 0;
    if(root == NULL){
        //*height = 0;
        return 1;
    }
    l = checkIsBalance(root->left, &leftHeight);
    r = checkIsBalance(root->right, &rightHeight);
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    cout<<"Node "<<root->data<<" has: height = "<<*height<<", leftHeight = "
    <<leftHeight<<", rightHeight = "<<rightHeight<<endl;
    if(abs(leftHeight - rightHeight) >=2){
        return 0;
    }
    else{
        return l && r;
    }
}

int main()
{
    int height = 0;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right = new Node(3);
    if(checkIsBalance(root,&height) == 1) cout<<"This is balance tree"<<endl;
    else cout<<"Not balance tree";
    
    return 0;
}