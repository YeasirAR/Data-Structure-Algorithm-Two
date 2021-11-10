#include<iostream>
using namespace std;
int maxArray(int array[100][100], int n,int m,int max){

}

int main(){
    int n,m,max=-1;
    int array[100][100];
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>array[i][j];
        }
    }
    max=maxArray(array,n,m,max);
    cout<<max;

    return 0;
}
