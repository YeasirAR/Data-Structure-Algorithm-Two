#include<iostream>
using namespace std;
#define INF 99999

void Merge(int A[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1], R[n2+1];
    int i=0, j=0;
    for(i=0; i<n1; i++){
        L[i] = A[p+i];
    }
    for(j=0; j<n2; j++){
        R[j] = A[q+j+1];
    }
    L[n1] = INF;
    R[n2] = INF;
    i=0, j=0;
    for(int k=p; k<=r; k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
    }
}
void Merge_Sort(int A[], int p, int r){
    if (p<r){
        int q=(p+r)/2;
        Merge_Sort(A, p, q);
        Merge_Sort(A, q+1, r);
        Merge(A, p, q, r);
    }
}

int main(){
    int n,x;
    cin>>n>>x;
    int cap[n];
    for(int i=0; i<n; i++){
        cin>>cap[i];
    }

    Merge_Sort(cap, 0, n-1);

    int count=0;
    for(int i=0; i<n; i++){
        if(x>=cap[i]){
            count++;
            x=x-cap[i];
        }
        else{
            break;
        }
    }
    cout<<count;
}

/*
5 10
8 5 4 3 2
*/
