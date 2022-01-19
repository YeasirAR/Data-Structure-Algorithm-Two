#include <iostream>

using namespace std;
int calc_factorial(int n);

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=n; i<=m; i++){
        cout<<i<<"! = "<<calc_factorial(i)<<endl;
    }
    return 0;
}
int calc_factorial(int n){
    if(n==0){
        return 1;
    }
    int sum=1;
    for(int i =1; i<=n; i++){
        sum=sum*i;
    }
    return sum;

}