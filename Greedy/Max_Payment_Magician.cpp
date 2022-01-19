#include<bits/stdc++.h>
using namespace std;

struct Magician{
    char classmate;
    char potion_name;
    int last_time;
    int time_needed;
    int price;
};
struct Output{
    vector<char> customers;
    int max_payment;
};

bool compare_to(Magician c1, Magician c2){
    return (c1.price/c1.time_needed)>(c2.price/c2.time_needed);
}

Output Magician_Potion(char classmate[],char potion_name[],int last_time[],
                            int time_needed[],int price[],int n){
                                
    Magician mg[n];
    for(int i=0; i<n; i++){
        mg[i].classmate=classmate[i];
        mg[i].potion_name=potion_name[i];
        mg[i].last_time=last_time[i];
        mg[i].time_needed=time_needed[i];
        mg[i].price=price[i];
    }
    sort(mg,mg+n,compare_to);

    vector<bool> available_time(6,true);

    Output out;
    out.max_payment=0;

    for(int i=0; i<n; i++){
        int count_available_time=0;
        for(int j=0; j<mg[i].last_time; j++){
            if(available_time[j]){
                count_available_time++;
            }
        }
        if(mg[i].time_needed<=count_available_time){
            int time_occupied=0;
            int k=mg[i].last_time-1;
            while(k>=0 && time_occupied!=mg[i].time_needed){
                if(available_time[k]){
                    time_occupied++;
                    available_time[k]=false;
                }
                k--;
            }
            out.max_payment+=mg[i].price;
            out.customers.push_back(mg[i].classmate);
        }
    }
    return out;
}

int main(){
    int n;
    cin>>n;
    char classmate[n];
    char potion_name[n];
    int last_time[n];
    int time_needed[n];
    int price[n];
    for(int i=0;i<n;i++){
        cin>>classmate[i]>>potion_name[i]>>last_time[i];
        if(potion_name[i]=='r'){
            time_needed[i]=2;
            price[i]=2000;
        }
        else if(potion_name[i]=='s'){
            time_needed[i]=1;
            price[i]=1000;
        }
        else if(potion_name[i]=='t'){
            time_needed[i]=1;
            price[i]=4000;
        }
        else if(potion_name[i]=='u'){
            time_needed[i]=2;
            price[i]=3000;
        }
        else if(potion_name[i]=='v'){
            time_needed[i]=1;
            price[i]=3000;
        }
    }
    Output out;
    out=Magician_Potion(classmate,potion_name,last_time,time_needed,price,n);

    cout<<endl<<out.customers[0];
    for(int i=1; i<out.customers.size(); i++){
        cout<<", "<<out.customers[i];
    }
    cout<<endl<<out.max_payment<<endl;

    return 0;
}


/*
Test Cases

5
a r 4
b s 1
c t 1
d u 4
e v 4

4
a r 4
b s 5
c t 1
d u 3


*/
