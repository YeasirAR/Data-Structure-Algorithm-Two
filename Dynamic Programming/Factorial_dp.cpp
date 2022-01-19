#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    int memo[100];
    memo[0]=1;
    memo[1]=1;
    for(int i=2; i<=n; i++){
        memo[i]=i*memo[i-1];
    }
    return memo[n];
}
int main(){
    int n;
    cin>>n;
    cout<<factorial(n);
}