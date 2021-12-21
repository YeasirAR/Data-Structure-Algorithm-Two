#include<bits/stdc++.h>
using namespace std;

struct Max_Table{
    float time;
    char ch;
};

bool compare_to(Max_Table c1, Max_Table c2){
    return c1.time<c2.time;
}

int Max_Table_Occupied(float arrival[],float departure[],int n, int m){
    Max_Table mt[n+m];
    for(int i=0; i<n; i++){
        mt[i].time=arrival[i];
        mt[i].ch='a';
    }
    for(int i=n,j=0; i<n+m; i++,j++){
        mt[i].time=departure[j];
        mt[i].ch='d';
    }
    sort(mt,mt+n+m,compare_to);
    int no_of_table=0;
    int max_table=0;
    float prev_arrival;
    for(int i=0; i<n+m; i++){
        if(mt[i].ch=='a'){
            no_of_table++;
            prev_arrival=mt[i].time;
        }
        else{
            if(no_of_table>max_table)
                max_table=no_of_table;
            if(prev_arrival==mt[i].time)
                max_table--;
            no_of_table--;
        }
    }
    return max_table;
}

int main(){
    float arival[]={2.00, 2.10, 3.00, 3.20, 3.50, 5.00};
    float departure[]={2.30, 3.40, 3.20, 4.30, 4.00, 5.20};
    //float arival[]={9.00, 9.40, 9.50, 11.00, 15.00, 18.00};
    //float departure[]={9.10, 12.00, 11.20, 11.30, 19.00, 20.00};
    int n=sizeof(arival)/sizeof(arival[0]);
    int m=sizeof(departure)/sizeof(departure[0]);
    cout<<Max_Table_Occupied(arival,departure,n,m);

    return 0;
}



