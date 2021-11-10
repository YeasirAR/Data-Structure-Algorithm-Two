#include<iostream>
using namespace std;
int maxArray(int array[], int n,int max){
    if(n<1){
        return max;
    }
    else{
        if(max<array[n-1]){
            max = array[n-1];
        }
        return maxArray(array,n-1,max);
    }
}

int main(){
    int n,max=-1;
    int array[100];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    max=maxArray(array,n,max);
    cout<<max;

    return 0;
}
