#include <iostream>
using namespace std;
int rec_power(int a,int b){
    if(b==0)
        return 1;
    return a* rec_power(a,b-1);
}

int main() {
    int a,b;
    cin>>a>>b;
    cout<<a<<"^"<<b<<" = "<<rec_power(a,b);
}
