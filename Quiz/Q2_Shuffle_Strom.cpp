#include<iostream>
using namespace std;
#define INF -99999

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
        if(L[i]>=R[j]){
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

int Binary_Search(int A[], int key, int start, int end){
    int mid = (start+end)/2;
    if(A[mid]==key){
        return mid;
    }
    else{
        if(end<=start)
            return 0;
        else{
            if(A[mid]<key)
                return Binary_Search(A, key, start, mid-1);
            else
                return Binary_Search(A, key, mid+1, end);
        }
    }
}


int main() {
    int A[100];
    int B[100];
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>A[i];
    }

    for (int i=0; i<n; i++){
        B[i]=A[i];
    }

    Merge_Sort(A, 0, n-1);

    for (int i=0; i<n; i++){
        int x = Binary_Search(A, B[i], 0,n-1);
        if(x>i)
            cout<<x-i<<" Right"<<endl;
        else if(x==i)
            cout<<"0"<<endl;
        else
            cout<<i-x<<" Left"<<endl;
    }
    return 0;
}
/*
8
3 5 6 9 4 1 2 7
*/

