#include<iostream>
#include<algorithm>
using namespace std;

struct Item_List{
    float v,w;
};
bool compare_to(Item_List c1, Item_List c2){
    return (c2.v/c2.w)<(c1.v/c1.w);
}
float Fractional_Knapsack(int W, Item_List item[], int size){
    sort(item, item+size,compare_to);
    int w = W;
    int sum = 0;
    for(int i=0; w>0 && i<size; i++){
        float wi = item[i].w;
        w=w-wi;
        if(w>=0)
            sum+=item[i].v;
    }
    return sum;
}

int main(){
    Item_List A[] ={{ 60, 10 }, { 100, 20 }, { 120, 30 }};
    int size=sizeof(A)/sizeof(A[0]);
    cout<< "Max Value: "<<Fractional_Knapsack(49,A,size);
}
