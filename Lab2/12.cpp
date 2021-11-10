#include<iostream>
using namespace std;
int revPrintArray(int array[], int n){
    if(n<1){
        return 0;
    }
    else{
        cout<<array[n-1]<<" ";
        return revPrintArray(array,n-1);
    }
}

int main(){
    int n;
    int array[100];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    revPrintArray(array,n);

    return 0;
}
