#include<iostream>
using namespace std;
#define INF 99999

void PrintArray(int arr[], int size);
void Quick_Sort(int A[], int p, int r);
int Partition(int A[], int p, int r);

int main() {
    int n, A[100];
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for (int i=0; i<n; i++){
        cin>>A[i];
    }

    Quick_Sort(A, 0, n-1);

    cout<<endl<<"Sorted Array: ";
    PrintArray(A, n);
    return 0;
}
void Quick_Sort(int A[], int p, int r){
    if (p<r){
        int q=Partition(A,p,r);
        Quick_Sort(A,p,q-1);
        Quick_Sort(A,q+1,r);
    }
}

int Partition(int A[], int p, int r){
    int x = A[r];
    int i = p-1;

    for(int j=p; j<r; j++){
        if(A[j]<=x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void PrintArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
/*void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
} */
