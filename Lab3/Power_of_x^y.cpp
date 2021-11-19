#include <iostream>
using namespace std;
int re_pow(int x, unsigned int y){
    if(y==0)
        return 1;
    int temp = re_pow(x,y/2);
    if(y%2==0){
        return temp*temp;
    }
    else
        return x*temp*temp;
}

int main() {
    int x,y;
    cin>>x>>y;
    cout<<x<<"^"<<y<<" = "<<re_pow(x,y);
}
