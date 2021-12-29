#include<bits/stdc++.h>
using namespace std;
#define NIL -1

int fibonacci(int memo[],int n){
    if(n==1 || n==2)
        return n-1;
    if(memo[n]!=NIL){
        return memo[n];
    }
    else{
        memo[n]=fibonacci(memo,n-1)+fibonacci(memo,n-2);
        return memo[n];
    }    
}

int main(){
    int n,memo[100];
    for(int i=0; i<100; i++){
        memo[i]=NIL;
    }
    cin>>n;
    cout<<fibonacci(memo,n);
}