#include<iostream>
using namespace std;

int printFibo(int n){
    int fibo1=0,fibo2=1;
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    return printFibo(n-1) + printFibo(n-2);
}

int main(){
    int n,Fibo;
    cin>>n;
    Fibo=printFibo(n);
    cout<<Fibo;
    return 0;
}
