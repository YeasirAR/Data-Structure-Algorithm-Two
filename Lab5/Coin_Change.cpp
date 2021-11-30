#include<bits/stdc++.h>
using namespace std;
#define NIL -1;
int greedy_coin_change(int M, vector<int> coinset){
    sort(coinset.begin(), coinset.end(),greater<int>());
    vector<int> sol;
    while(M>0){
        bool coin_chosen = false;
        for(int coin: coinset){
            if(coin>M) continue;
            sol.push_back(coin);
            M-= coin;
            coin_chosen = true;
            break;
        }
        if(!coin_chosen){
            cout<<"No solution for this problem"<<endl;
            return NIL;
        }
        cout<<"Yet to pay "<<M<< " taka."<<endl;

    }
    for(int coin: sol){
        cout <<"Solution is: "<< coin<<"+";
    }
    cout<<endl;
    return sol.size();

}

int main(){
    int M = 50;
    vector<int> coinset={5,10,25};
    cout<<greedy_coin_change(M,coinset)<<endl;

}
