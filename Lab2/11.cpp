#include<iostream>
using namespace std;
int Count(int array[], int n,int &countE,int &countO){
    if(n<1){
        return 0;
    }
    else{
        if(array[n-1]%2 == 0)
            countE++;
        else
            countO++;
        return Count(array,n-1,countE,countO);
    }
}

int main(){
    int n,countE=0,countO=0;
    int array[100];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    Count(array,n,countE,countO);
    cout<<"No of EVEN number: "<<countE<<endl;
    cout<<"No of ODD number: "<<countO<<endl;

    return 0;
}
