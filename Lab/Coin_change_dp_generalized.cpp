#include<iostream>
using namespace std;
int INF = 0x7f7f7f7f;

int coinchange(int coins[], int total, int n)
{
    int dp[n][total+1];
    for(int i=0;i<n;i++)
        dp[i][0] = 0;
    for(int i=1;i<total+1;i++)
    {
        if(i%coins[0]==0)
            dp[0][i] = (i/coins[0]);
        else
            dp[0][i] = INF;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<total+1;j++)
        {
            if(coins[i]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i]]);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<total+1;j++)
        {
            if(dp[i][j]>=INF)
                cout << "INF";
            else
                cout << dp[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    return dp[n-1][total];
}


int main()
{
    int coins[3] = {1,4,6};
    int total = 11;
    int n = sizeof(coins)/sizeof(coins[0]);
    int result = coinchange(coins, total, n);
    if(result>=INF)
        cout << "Impossible\n";
    else
        cout << "Minimum Coin(s) Needed: " << result << "\n";

    return 0;
}
