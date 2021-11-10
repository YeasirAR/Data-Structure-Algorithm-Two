#include<iostream>
using namespace std;
int minArray(int array[], int n,int min){
    if(n<1){
        return min;
    }
    else{
        if(min>array[n-1]){
            min = array[n-1];
        }
        return minArray(array,n-1,min);
    }
}

int main(){
    int n,min=9999;
    int array[100];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    min=minArray(array,n,min);
    cout<<min;

    return 0;
}
