#include<iostream>
using namespace std;
int INF = 0x7f7f7f7f;

int coinchange(int coins[], int total, int n)
{
    int dp[n][total+1];
    for(int i=0;i<n;i++)
        dp[i][0] = 1;
    for(int i=1;i<total+1;i++)
    {
        if(i%coins[0]==0)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<total+1;j++)
        {
            if(coins[i]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<total+1;j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return dp[n-1][total];
}


int main()
{
    int coins[3] = {2,4,6};
    int total = 10;
    int n = 3;
    int result = coinchange(coins, total, n);
    cout << "No of ways: " << result << "\n";

    return 0;
}
