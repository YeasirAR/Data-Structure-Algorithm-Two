#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define NIL -1
int coin_change(int M, int c[], int d){
    int best_num_coins[M+1];
    int chosen_coin[M+1];
    best_num_coins[0]=0;
    chosen_coin[0]=NIL;
    for(int m=1; m<=M; m++){
        best_num_coins[m]=INF;
        cout << "to form "<< m<< " taka"<<endl;
        for(int i=0; i<d; i++){
            if(m>= c[i]){
                cout<<"\tconsidering coin "<<c[i];
                int nc = 1+best_num_coins[m-c[i]];
                cout <<": will need "<< nc<< " coins"<<endl;
                if(nc<best_num_coins[m]){
                    best_num_coins[m]=nc;
                    chosen_coin[m]=c[i];
                    cout <<"\t\tchose it"<<endl;
                }
            }

        }
    }
    for(int i=0; i<=M; i++){
        cout<<best_num_coins[i]<<", chosen coin "<<chosen_coin[i]<<endl;
    }
    cout << "solution includes: ";
    int money =M;
    while (money>0){
        cout << chosen_coin[money]<<" " ;
        money = money - chosen_coin[money];
    }
    cout << endl;

    return best_num_coins[M];
}
int main(){
    int M = 21;
    int c[]={2,3,4,7};
    int d = sizeof(c)/sizeof(c[0]);
    int nc = coin_change(M,c,d);
    cout<<"need minimum "<< nc << " coins"<<endl;
}
