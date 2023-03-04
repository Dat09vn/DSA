#include<iostream>
using namespace std;
int n;
int arr[100] = {0};
int kq[100] = {0};

void printF(int arrr[], int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        cout<<arrr[i];
    }
    cout<<" ";
}

void backtrack(int i){
    if(i>n){
        printF(kq,n);
    }
    for(int j=1; j<=n; j++){
        if(arr[j] == 0){
            kq[i] = j;
            arr[j] = 1;
            backtrack(i+1);
            arr[j] = 0;
        }
    }
}


//--------------------alternative

// void backtrack(int i){
//     for(int j=1; j<=n; j++){
//         if(arr[j] == 0){
//             kq[i] = j;
//             arr[j] = 1;
//             if( i == n){
//                 printF(kq,n);
//             }
//             else{
//                 backtrack(i+1);
//             }
//             arr[j] = 0;
//         }
//     }
// }


int main(){
    cin>>n;
    backtrack(1);
    return 0;
}