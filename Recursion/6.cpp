#include<iostream>
using namespace std;
int sumArray(int array[], int n){
    int ret,sum;
    if(n<1){
        return 0;
    }
    else{
        ret = sumArray(array,n-1);
        sum = ret+array[n-1];
        return sum;
    }
}

int main(){
    int n,sum;
    int array[100];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    sum=sumArray(array,n);
    cout<<sum;

    return 0;
}
