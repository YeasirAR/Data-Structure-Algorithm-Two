#include<iostream>
using namespace std;
#define INF 99999

bool Binary_Search(int A[], int key, int start, int end, int &x){
    int mid = (start+end)/2;
    if(A[mid]==key){
        x=mid;
        return true;
    }
    else{
        if(end<=start)
            return false;
        else{
            if(A[mid]>key)
                return Binary_Search(A, key, start, mid-1,x);
            else
                return Binary_Search(A, key, mid+1, end,x);
        }
    }
}

void x_occurrence(int A[], int x, int start, int end, int& count){
    for(int i=x-1; i>=0; i--){
        if(A[i]==A[x])
            count++;
        else
            break;
    }
    for(int i=x+1; i<=end; i++){
        if(A[i]==A[x])
            count++;
        else
            break;
    }
}

int main() {
    int n, key, x;
    int A[] = {1, 1, 2, 2, 2, 2, 30};
    n = sizeof(A) / sizeof(A[0]);
    cout<<"Enter the value of key: ";
    cin>>key;

    bool flag=Binary_Search(A, key, 0,n-1,x);
    if(flag){
        int count=1;
        x_occurrence(A,x,0,n-1,count);
        cout<<count;
    }
    return 0;
}

