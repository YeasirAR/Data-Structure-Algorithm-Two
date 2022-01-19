#include<iostream>
using namespace std;
int Print(int range1,int range2){
    if(range1>range2){
        return 0;
    }
    else{
        if(range1%2==0){
            cout<<range1<<" ";
        }
        return Print(range1+1,range2);
    }
}

int main(){
    int r1,r2;
    cin>>r1>>r2;
    Print(r1,r2);

    return 0;
}
