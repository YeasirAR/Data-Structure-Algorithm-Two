#include<bits/stdc++.h>
using namespace std;
int min_stone(vector<int> stones,int total_sum,int n){
    int count=0,element_sum=0;
    for(int i=0; i<n; i++){
        if(element_sum<total_sum){
            count++;
            element_sum+=stones[i];
            total_sum-=stones[i];
        }
        else{
            break;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int> stones(n);
    for(int i=0; i<n; i++){
        cin>>stones[i];
    }
    sort(stones.begin(),stones.end(),greater<int>());
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=stones[i];
    }
    cout<<min_stone(stones,sum,n);

}
/*
8
2 3 4 1 2 1 5 3
*/