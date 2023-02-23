#include <iostream>
using namespace std;
void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}



int main(){

    int n;
    cin>>n;
    int arrIndex[n] = {};
    int arrValue[n] = {};
    
    for(int i=0; i<n; i++){
        cin>>arrValue[i];
        arrIndex[i] = i;
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arrValue[i] > arrValue[j]){
                swap(arrValue[i],arrValue[j]);
                swap(arrIndex[i],arrIndex[j]);
            }
        }
    }
    printArr(arrIndex,n);


    return 0;
}