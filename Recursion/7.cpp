#include<iostream>
using namespace std;
int proArray(int array[], int n){
    int ret,product;
    if(n<1){
        return 1;
    }
    else{
        ret = proArray(array,n-1);
        product = ret*array[n-1];
        return product;
    }

}

int main(){
    int n,product;
    int array[100];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    product=proArray(array,n);
    cout<<product;

    return 0;
}
