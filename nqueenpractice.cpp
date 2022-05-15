#include<iostream>
#include<vector>
using namespace std;

void printsoln(vector<vector<int>> &b){
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b.size();j++){
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool issafe(int row,int col,vector<vector<int>> &b){
    for(int i=0;i<col;i++){
        if(b[row][i]==1){
            return false;
        }
    }
    for(int i=row, j=col;i<b.size() && j>=0;i++,j-- ){
        if(b[i][j]==1){
            return false;
        }
    }
    for(int i=row, j=col; i>=0 && j>=0 ;i--,j--){
        if(b[i][j]==1){
            return false;
        }
    }
return true;
}

void nqueen(vector<vector<int>> &b,int col){
if(col>=b.size()){
    cout<<"solution: \n";
    printsoln(b);    
    return;
}
for(int i=0;i<b.size();i++){
 if(issafe(i,col,b)){
     b[i][col]=1;
     nqueen(b,col+1);
     b[i][col]=0;
 }
}
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> b(n,vector<int> (n,0));
    if(n==2 || n==3){
        cout<<"sol doesnt exist\n";
        return 0;
    }
nqueen(b,0);
}