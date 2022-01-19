#include<iostream>
using namespace std;
#define INF 99999

void PrintArray(int arr[], int size);
int Merge_Sort(int A[], int p, int r);
int Merge(int A[], int p, int q, int r);

int main() {
    int n, A[100];
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for (int i=0; i<n; i++){
        cin>>A[i];
    }

    int ic;
    ic=Merge_Sort(A, 0, n-1);

    cout<<endl<<"Sorted Array: ";
    PrintArray(A, n);
    cout<<endl<<"No of inversion: "<<ic<<endl;
    return 0;
}
int Merge_Sort(int A[], int p, int r){
    int ic=0;
    if (p<r){
        int q=(p+r)/2;
        ic+=Merge_Sort(A, p, q);
        ic+=Merge_Sort(A, q+1, r);
        ic+=Merge(A, p, q, r);
    }
    return ic;
}

int Merge(int A[], int p, int q, int r){
    int ic=0;
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1], R[n2+1];
    int i=0, j=0;

    for(i=0; i<n1; i++)
        L[i] = A[p+i];
    for(j=0; j<n2; j++)
        R[j] = A[q+j+1];

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
            ic+=n1-i;
        }
    }
    return ic;
}

void PrintArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
