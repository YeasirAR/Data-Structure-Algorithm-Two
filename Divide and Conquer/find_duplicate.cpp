#include<iostream>
using namespace std;

bool Binary_Search(int A[], int start, int end, int &x){
    int mid = (start+end)/2;
    if(A[mid]==A[mid-1] || A[mid]==A[mid+1]){
        x=A[mid];
        return true;
    }
    else{
        if(end<=start)
            return false;
        else{
            if(A[mid]==(A[start]+A[end])/2) // pppp
                return Binary_Search(A, start, mid-1,x);
            else
                return Binary_Search(A, mid+1, end,x);
        }
    }
}


int main() {
    int n, x, A[100];
    //int A[] = {1, 2, 2, 2, 2, 30};
    //int A[] = {1, 2, 25, 25, 27, 30};
    //int A[] = {21, 41, 52, 62, 72, 72, 72, 300};
    //n = sizeof(A) / sizeof(A[0]);

    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for (int i=0; i<n; i++){
        cin>>A[i];
    }

    Binary_Search(A, 0,n-1,x);
    cout<<x;

    return 0;
}

