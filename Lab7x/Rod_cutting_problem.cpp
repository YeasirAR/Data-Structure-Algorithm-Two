#include <bits/stdc++.h>
using namespace std;
#define INF 99999
int rod_cut(int n, int p[]){
    int profit[n+1];
    int chosen_rod[n+1];
    profit[0]=0;

    for(int L=1; L<=n; L++){
        profit[L] = -INF;
        for(int rod=1; rod<=L; rod++){
            int curr_profit = p[rod]+profit[L-rod];
            if(curr_profit > profit[L]){
                profit[L] = curr_profit;
                chosen_rod[L]=rod;
            }
        }
    }
    //print chosen rod
    return profit[n];

}
int main(){
    int p[]={0,1,5,8,9,10,17,20,24,30};
    cout<<rod_cut(4,p)<<endl;
}
