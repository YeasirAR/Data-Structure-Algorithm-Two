#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){
    int memo[100];
    memo[0]=0;
    memo[1]=1;
    for(int i=2; i<n; i++){
        memo[i]=memo[i-1]+memo[i-2];
    }
    return memo[n-1];
}
int main(){
    int n;
    cin>>n;
    cout<<fibonacci(n);
}