#include<iostream>
using namespace std;

int arr[100] = {0}; 
int kq[100] = {0};

void printF(int m_arr[], int x){
    for(int i=1; i<=x; i++){
        cout<<m_arr[i]<<" ";
    }
    cout<<endl;
}

void Try(int n){
    for(int i=kq[n-1]+1;i<=6;i++){
        if(arr[i] == 0){
            kq[n] = i;
            arr[i] = 1;
            // cout<<"i:"<<i<<"--- n:"<<n<<endl;
            // cout<<"kq: "<<kq[n]<<endl;
            printF(kq,n);
            Try(n+1);
            // cout<<"reset:"<<i<<endl;
            arr[i]=0;
        }

    }
}

int main(){
    Try(1);
    return 0;
}