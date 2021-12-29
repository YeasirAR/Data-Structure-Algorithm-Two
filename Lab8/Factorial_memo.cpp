#include<bits/stdc++.h>
using namespace std;
#define NIL -1

int factorial(int memo[],int n){
    if(n==0 || n==1)
        return 1;
    if(memo[n]!=NIL){
        return memo[n];
    }
    else{
        memo[n]=n*factorial(memo,n-1);
        return memo[n];
    }    
}

int main(){
    int n,memo[100];
    for(int i=0; i<100; i++){
        memo[i]=NIL;
    }
    cin>>n;
    cout<<factorial(memo,n);
}