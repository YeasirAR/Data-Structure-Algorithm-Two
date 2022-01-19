#include<iostream>
using namespace std;
float avgArray(int array[], int n,int m,float avg){
    if(n<1){
        return avg;
    }
    else{
        avg = avg + (array[n-1]/m);
        return avgArray(array,n-1,m,avg);
    }
}

int main(){
    int n;
    float avg=0.0;
    int array[100];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    avg=avgArray(array,n,n,avg);
    cout<<avg;

    return 0;
}
