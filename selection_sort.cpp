#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    int i=0;
    while(i<n){
        int mini=1e9;
        int minind=-1;
        for(int j=i;j<n;j++){
            if(v[j]<mini){
            mini=v[j];
            minind=j;           
            }
        }
        int temp=v[i];
        v[i]=v[minind];
        v[minind]=temp;
        i++;
    }

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}