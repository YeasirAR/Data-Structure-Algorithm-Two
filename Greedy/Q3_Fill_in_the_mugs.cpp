#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    int cap[n];
    int exit[n];
    for(int i=0; i<n; i++){
        cin>>cap[i];
    }
    sort(cap,cap+n);
    int count=0;
    for(int i=0; i<n; i++){
        if(x>=cap[i]){
            count++;
            x=x-cap[i];
        }
    }
    cout<<count;
}

/*
5 10
8 5 4 3 2
*/