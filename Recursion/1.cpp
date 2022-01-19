#include<iostream>
using namespace std;
int calcFact(int n){
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    return n*calcFact(n-1);
}

int main(){
    int n,fact;
    cin>>n;
    fact=calcFact(n);
    cout<<fact;
}
