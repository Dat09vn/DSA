#include <iostream>
using namespace std;
#define N 4

    bool isOk(int b[][N], int row, int col){
        //check row
        //cout<<"true 1";
        for(int i=0;i<col;i++){
            //cout<<"while1";
            if(b[row][i]){
                //cout<<"false 1";
                return false;
            }
        }

        //check duong cheo tren
        int i = row;
        int j = col;
        while(i>=0 && j>=0){
            //cout<<"while 2";
            if(b[i][j]){
                //cout<<"false 2";
                return false;
            }
            i--;
            j--;
        }

        //check duong cheo duoi
        i=row;
        j=col;
        while(i<N && j>=0){
            //cout<<"while 3";
            if(b[i][j]){
                //cout<<"false 3";
                return false;
            }
            i++;
            j--;
        }
        //cout<<"true 2";
        return true;
    }

    void enterBoard(int b[][N]){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                b[i][j]=0;
            }
        }
    }

    void showResult(int b[][N]){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void setQueens(int b[][N], int col){
        if(col>=N){
            showResult(b);
            cout<<endl;
        }
        for(int i=0; i<N; i++){
            
            if(isOk(b,i,col)){
                //cout<<"true i,j"<<i<<col<<endl;
                b[i][col] = 1;
                
                setQueens(b,col+1);
                b[i][col] = 0;
            }
        }
    }


int main(){
    int b[N][N];
    enterBoard(b);
    setQueens(b,0);
    //showResult(b);
    

    return 0;
}