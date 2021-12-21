#include<bits/stdc++.h>
using namespace std;

struct PhotoShop{
    char customer;
    int last_time;
    int time_needed;
    int payment;
};
struct Output{
    vector<char> customers;
    int max_payment;
};

bool compare_to(PhotoShop c1, PhotoShop c2){
    return c1.payment>c2.payment;
}

Output PhotoShop_Editor(char customer[],int last_time[],
                            int time_needed[],int payment[],int n){
    PhotoShop ps[n];
    for(int i=0; i<n; i++){
        ps[i].customer=customer[i];
        ps[i].last_time=last_time[i];
        ps[i].time_needed=time_needed[i];
        ps[i].payment=payment[i];
    }
    sort(ps,ps+n,compare_to);

    vector<bool> available_time(8,true);

    Output out;
    out.max_payment=0;

    for(int i=0; i<n; i++){
        int count_available_time=0;
        for(int j=0; j<ps[i].last_time; j++){
            if(available_time[j]){
                count_available_time++;
            }
        }
        if(ps[i].time_needed<=count_available_time){
            int time_occupied=0;
            int k=ps[i].last_time-1;
            while(k>=0 && time_occupied!=ps[i].time_needed){
                if(available_time[k]){
                    time_occupied++;
                    available_time[k]=false;
                }
                k--;
            }
            out.max_payment+=ps[i].payment;
            out.customers.push_back(ps[i].customer);
        }
    }
    return out;
}

int main(){
    int n;
    cin>>n;
    char customer[n];
    int last_time[n];
    int time_needed[n];
    int payment[n];
    for(int i=0;i<n;i++){
        cin>>customer[i]>>last_time[i]>>payment[i];
        time_needed[i]=1;
    }
    Output out;
    out=PhotoShop_Editor(customer,last_time,time_needed,payment,n);

    cout<<endl<<out.customers[0];
    for(int i=1; i<out.customers.size(); i++){
        cout<<", "<<out.customers[i];
    }
    cout<<endl<<out.max_payment<<endl;

    return 0;
}


/*
Test Cases

4
a 4 2000
b 1 1000
c 1 4000
d 1 3000

5
a 2 1000
b 1 190
c 2 270
d 1 250
e 3 150


3
a 2 1000
b 4 1000
c 4 500

*/
