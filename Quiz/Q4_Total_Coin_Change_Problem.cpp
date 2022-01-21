#include<iostream>
using namespace std;

int total_no_of_ways(int S[], int amount, int n){
    int memo[n][amount+1];

    for(int i=0;i<n;i++){
        memo[i][0] = 1;
    }
    for(int i=1;i<amount+1;i++) {
        if(i%S[0]==0){
            memo[0][i] = 1;
        }  
        else{
            memo[0][i] = 0;
        }
            
    }

    for(int i=1;i<n;i++) {
        for(int j=1;j<amount+1;j++) {
            if(S[i]>j){
                memo[i][j] = memo[i-1][j];
            }
            else{
                memo[i][j] = memo[i-1][j] + memo[i][j-S[i]];
            }
                
        }
    }
    return memo[n-1][amount];
}

int main(){

    int S[] = {1,3,5,7};
    int amount = 8;
    int n = sizeof(S)/sizeof(S[0]);
    int no_of_ways = total_no_of_ways(S, amount, n);
    cout << "The total number of ways is " << no_of_ways <<endl;

    return 0;
}
