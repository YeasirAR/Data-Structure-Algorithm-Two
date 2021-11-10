#include<iostream>
using namespace std;

int countDigits(int n, int count=0){
    if(n!=0){
        count++;
        return countDigits(n/10,count);
    }
    else{
        return count;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<countDigits(n);;
    return 0;
}
