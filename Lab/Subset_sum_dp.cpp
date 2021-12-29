#include <bits/stdc++.h>
using namespace std;
#define INF 99999
int subset_sum(int W, int v[],int w[], int n){
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
                if(v_i+P[i-1][ww-w_i]){
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
    cout<<subset_sum(W,v,w,n)<<endl;

}

/*
// A Dynamic Programming solution
// for subset sum problem
#include <stdio.h>

// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
	// The value of subset[i][j] will be true if
	// there is a subset of set[0..j-1] with sum
	// equal to i
	bool subset[n + 1][sum + 1];

	// If sum is 0, then answer is true
	for (int i = 0; i <= n; i++)
		subset[i][0] = true;

	// If sum is not 0 and set is empty,
	// then answer is false
	for (int i = 1; i <= sum; i++)
		subset[0][i] = false;

	// Fill the subset table in bottom up manner
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j] = subset[i - 1][j]
							|| subset[i - 1][j - set[i - 1]];
		}
	}

	 // uncomment this code to print table
	for (int i = 0; i <= n; i++)
	{
	for (int j = 0; j <= sum; j++)
		printf ("%4d", subset[i][j]);
	printf("\n");
	}//

	return subset[n][sum];
}

// Driver code
int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		printf("Found a subset with given sum");
	else
		printf("No subset with given sum");
	return 0;
}
// This code is contributed by Arjun Tyagi.
*/