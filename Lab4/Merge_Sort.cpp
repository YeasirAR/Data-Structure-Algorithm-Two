#include<iostream>
using namespace std;
#define INF 99999

void PrintArray(int arr[], int size);
void Merge_Sort(int A[], int p, int r);
void Merge(int A[], int p, int q, int r);

int main() {
    int n, A[100];
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for (int i=0; i<n; i++){
        cin>>A[i];
    }

    Merge_Sort(A, 0, n-1);

    cout<<endl<<"Sorted Array: ";
    PrintArray(A, n);
    return 0;
}
void Merge_Sort(int A[], int p, int r){
    if (p<r){
        int q=(p+r)/2;
        Merge_Sort(A, p, q);
        Merge_Sort(A, q+1, r);
        Merge(A, p, q, r);
    }
}

void Merge(int A[], int p, int q, int r){
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
        }
    }
}

void PrintArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
