#include<iostream>
using namespace std;

int calcPower(int x, int y){
    if(y==0)
        return 1;
    return x*calcPower(x,y-1);

}

int main(){
    int x,y,res;
    cin>>x>>y;
    res=calcPower(x,y);
    cout<<res;
    return 0;
}
