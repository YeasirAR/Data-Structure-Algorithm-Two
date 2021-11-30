#include<bits/stdc++.h>
using namespace std;

struct A{
    int i,s,f;
};
bool comp(A a1, A a2){
    return a1.f<a2.f;
}
void activity_selection(int s[],int f[],int n){
    A as[n];
    for(int i=0; i<n; i++){
        as[i].i=i;
        as[i].s=s[i];
        as[i].f=f[i];
    }
    sort(as,as+n,comp);
    vector<A> sol;
    sol.push_back(as[0]);
    int k=0;
    for(int m=1; m<n; m++){
        if(as[m].s >= as[k].f){
            sol.push_back(as[m]);
            k=m;
        }
    }
    for(A a: sol){
        cout << a.i << " "<< a.s << " "<<a.f<<endl;
    }
}

int main(){
    int s[]={4,2,1,8};
    int f[]={6,7,6,11};
    int n = sizeof(s)/sizeof(s[0]);
    activity_selection(s,f,n);
}
