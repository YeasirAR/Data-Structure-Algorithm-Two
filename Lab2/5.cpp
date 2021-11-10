#include<iostream>
using namespace std;

int sumDigits(int n, int sum=0){
    if(n!=0){
        sum+=n%10;
        return sumDigits(n/10,sum);
    }
    else{
        return sum;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<sumDigits(n);;
    return 0;
}
