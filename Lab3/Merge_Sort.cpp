#include<iostream>
using namespace std;

#define INFINITY 999999

void merge(int A[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1], R[n2+1];

//    for(int i=1;i<=n1;i++)
//        L[i-1] = A[p+i-1];
    for(int i=0;i<n1;i++)
        L[i] = A[p+i];

//    for (int j=1;j<=n2;j++)
//        R[j-1] = A[q+j];

    for (int j=0;j<n2;j++)
        R[j] = A[q+1+j];

    L[n1] = INFINITY;
    R[n2] = INFINITY;

    int i=0, j=0;
    for (int k=p;k<=r;k++){

        if (L[i]<=R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int A[], int p, int r){
    if (p<r){
        int q = (p+r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}


int main(){
    int arr[100];
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> arr[i];

    cout << "Before sorting ";
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";

    merge_sort(arr, 0, n-1);

    cout << "\nAfter sorting ";
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
