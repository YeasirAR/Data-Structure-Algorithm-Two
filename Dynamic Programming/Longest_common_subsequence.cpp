#include<iostream>
using namespace std;


int lcs(char x[],char y[],int xl,int yl){
    int tab[xl+1][yl+1];
    string sign[xl+1][yl+1];
    for(int i=0;i<=xl;i++){
        tab[i][0]=0;
    }
    for(int i=0;i<=yl;i++){
        tab[0][i]=0;
    }
    for(int i=1;i<=xl;i++){
        for(int j=1;j<=yl;j++){
            if(x[i-1]==y[j-1]){
                tab[i][j] = tab[i-1][j-1] + 1;
                sign[i][j] = "Diagonal";
            }
            else if(tab[i-1][j] >= tab[i][j-1]){
                tab[i][j]=tab[i-1][j];
                sign[i][j] = "TOP";
            }
            else{
                tab[i][j]=tab[i][j-1];
                sign[i][j] = "LEFT";
            }
        }
    }
    //printing 
    return tab[xl][yl];
    
}


int main()
{
    char x[]="AGGTAB";
    char y[]="GXTXAYB";
    int xl = 6;
    int yl = 7;
    //int xl = sizeof(x)/sizeof(x[0]);
    //int yl = sizeof(y)/sizeof(y[0]);
    cout<<lcs(x,y,xl,yl);
    return 0;
}
/*
Print-LCS (B, X, i, j)
if i = 0 and j = 0 
   return  
if B[i, j] = ‘D’ 
   Print-LCS(B, X, i-1, j-1) 
   Print(xi) 
else if B[i, j] = ‘U’ 
   Print-LCS(B, X, i-1, j) 
else 
   Print-LCS(B, X, i, j-1) 



#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

void lcs( char *X, char *Y, int m, int n )
{
int L[m+1][n+1];

 Following steps build L[m+1][n+1] in bottom up fashion. Note
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] 
for (int i=0; i<=m; i++)
{
	for (int j=0; j<=n; j++)
	{
	if (i == 0 || j == 0)
		L[i][j] = 0;
	else if (X[i-1] == Y[j-1])
		L[i][j] = L[i-1][j-1] + 1;
	else
		L[i][j] = max(L[i-1][j], L[i][j-1]);
	}
}

// Following code is used to print LCS
int index = L[m][n];

// Create a character array to store the lcs string
char lcs[index+1];
lcs[index] = '\0'; // Set the terminating character

// Start from the right-most-bottom-most corner and
// one by one store characters in lcs[]
int i = m, j = n;
while (i > 0 && j > 0)
{
	// If current character in X[] and Y are same, then
	// current character is part of LCS
	if (X[i-1] == Y[j-1])
	{
	lcs[index-1] = X[i-1]; // Put current character in result
	i--; j--; index--;	 // reduce values of i, j and index
	}

	// If not same, then find the larger of two and
	// go in the direction of larger value
	else if (L[i-1][j] > L[i][j-1])
	i--;
	else
	j--;
}

// Print the lcs
cout << "LCS of " << X << " and " << Y << " is " << lcs;
}

int main()
{
char X[] = "AGGTAB";
char Y[] = "GXTXAYB";
int m = strlen(X);
int n = strlen(Y);
lcs(X, Y, m, n);
return 0;
}

*/