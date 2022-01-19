#include <bits/stdc++.h>
using namespace std;
#define INF 99999
int knapsack(int W, int v[],int w[], int n){
    int P[n+1][W+1];
    for(int ww=0; ww<=W;ww++){
        P[0][ww] = 0;
    }
    for(int i=0; i<=n;i++){
        P[i][0] = 0;
    }
    for(int i=1; i<=n;i++){
        for(int ww=1; ww<=W;ww++){
            int w_i = w[i-1];
            int v_i = v[i-1];
            if(w_i <= ww){
                if(v_i+P[i-1][ww-w_i] > P[i-1][ww]){
                    P[i][ww]=v_i+P[i-1][ww-w_i];
                }
                else{
                    P[i][ww]=P[i-1][ww];
                }
            }
            else{
                P[i][ww]=P[i-1][ww];
            }
        }
    }
    return P[n][W];
}
int main(){
    int W = 15;
    int v[]={20,29};
    int w[]={10,15};
    int n=sizeof(v)/sizeof(v[0]);
    cout<<knapsack(W,v,w,n)<<endl;

}
