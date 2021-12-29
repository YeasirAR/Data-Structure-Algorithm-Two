#include<iostream>
using namespace std;
#define INF 99999;

int coinchange(int coins[], int total, int n)
{
    if(total ==0)
        return 0;
    int memo=INF;
    for(int i=1;i<=n;i++){
        if(total>=coins[i]){
            int numcoins = coinchange(coins,total-coins[i],n);//some issue here!
            if(numcoins+1 <memo){
                memo=numcoins+1;
            }
        }    
    }
    return memo;

}


int main()
{
    int coins[3] = {1,4,6};
    int total = 11;
    int n = sizeof(coins)/sizeof(coins[0]);
    int result = coinchange(coins, total, n);
    cout << "Minimum Coin(s) Needed: " << result << "\n";
    return 0;
}



/*
#include <bits/stdc++.h>
using namespace std;
 
int coinchange(vector<int>& a, int v, int n,
               vector<vector<int> >& dp)
{
    if (v == 0)
        return dp[n][v] = 1;
    if (n == 0)
        return 0;
    if (dp[n][v] != -1)
        return dp[n][v];
    if (a[n - 1] <= v) {
        // Either Pick this coin or not
        return dp[n][v] = coinchange(a, v - a[n - 1], n, dp)
                          + coinchange(a, v, n - 1, dp);
    }
    else // We have no option but to leave this coin
        return dp[n][v] = coinchange(a, v, n - 1, dp);
}
int32_t main()
{
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        int n, v;
        n = 3, v = 4;
        vector<int> a = { 1, 2, 3 };
        vector<vector<int> > dp(n + 1,
                                vector<int>(v + 1, -1));
        int res = coinchange(a, v, n, dp);
        cout << res << endl;
    }
}
*/