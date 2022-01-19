#include<bits/stdc++.h>
using namespace std;

struct Programmer{
    char name;
    int time_needed;
    int payment;
};
struct Output{
    vector<char> customers;
    int max_payment;
};

bool compare_to(Programmer c1, Programmer c2){
    return (c1.payment/c1.time_needed)>(c2.payment/c2.time_needed);
}

Output Parttime_Programmer(int C, int N,char name[],
                        int time_needed[],int payment[]){
    Programmer ps[N];
    for(int i=0; i<N; i++){
        ps[i].name=name[i];
        ps[i].time_needed=time_needed[i];
        ps[i].payment=payment[i];
    }
    sort(ps,ps+N,compare_to);

    Output out;
    out.max_payment=0;

    for(int i=0; i<N; i++){
        if(ps[i].time_needed<=C){
            C-=ps[i].time_needed;
            out.max_payment+=ps[i].payment;
            out.customers.push_back(ps[i].name);
        }
    }
    return out;
}

int main(){
    int C,N;
    cin>>C>>N;
    char name[N];
    int time_needed[N];
    int payment[N];
    for(int i=0;i<N;i++){
        cin>>name[i]>>time_needed[i]>>payment[i];
    }
    Output out;
    out=Parttime_Programmer(C,N,name,time_needed,payment);

    cout<<endl<<out.max_payment<<endl;
    for(int i=0; i<out.customers.size(); i++){
        cout<<out.customers[i]<<endl;
    }

    return 0;
}


/*
Test Cases

5
5
A 2 6000
B 2 1000
C 1 1200
D 2 2000
E 1 3000

5
4
B 2 1000
C 1 1200
D 2 2000
E 1 3000

GREEDY doesn't provide an optimal answer for this problem!

*/
