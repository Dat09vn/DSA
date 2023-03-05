#include <iostream>
using namespace std;
    int n=7;int k=3;
    int arr[6]={0};
    int kq[100]={0};

void printF(int arrr[],int n){
    for(int i=1;i<=n;i++){
        cout<<arrr[i]<<" ";
    }
    cout<<endl;
}

void backtrack(int x){
    for(int i=kq[x-1]+1;i<=n-k+x;i++){
        kq[x] = i;
        if(x == k){
            printF(kq,k);
        }
        else{
            backtrack(x+1);
        }
    }
}


int main(){
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }
    backtrack(1);
}
