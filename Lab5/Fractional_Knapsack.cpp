#include<iostream>
#include<algorithm>
using namespace std;

struct Item{
    float v,w;
};
bool comp(Item i1, Item i2){
    return i1.v/i1.w > i2.v/i2.w;
}
void fractional_knapsack(int W, Item items[], int n){
    sort(items, items+n,comp);
    int w = W;
    int i=0;
    while (w>0 && i<n){
        cout<< "Picked item "<<i<<"( "<< items[i].v<<", "<<items[i].w<<") "<<endl;
        float wi = items[i].w;
        float xi = min(1.0,w*1.0/wi);
        cout<<"\t"<<xi<<endl;
        w=w-xi*wi;
        i++;
    }
    //add return here!
}

int main(){
    Item arr[] ={{1,4},{8,4},{3,4},{1,7},{5,6},{9,4},{4,3}};
    int n=sizeof(arr)/sizeof(arr[0]);
    fractional_knapsack(7,arr,n);
}
