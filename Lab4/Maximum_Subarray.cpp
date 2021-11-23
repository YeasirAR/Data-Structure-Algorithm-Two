#include<iostream>
using namespace std;

#define P_INF 99999
#define N_INF -99999

struct MaxSub{
    int left;
    int right;
    int sum;
};

MaxSub find_max_crossing_subarray(int A[], int low, int mid, int high){
    int left_sum = N_INF, max_left;
    int sum = 0;
    for (int i=mid; i>=low;i--){
        sum += A[i];
        if (sum>left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = N_INF, max_right;
    sum = 0;
    for (int i=mid+1; i<=high;i++){
        sum += A[i];
        if (sum>right_sum){
            right_sum = sum;
            max_right = i;
        }
    }

    return {max_left,max_right,left_sum+right_sum};
}

MaxSub find_maximum_subarray(int A[], int low, int high){
    if (high == low){
        return {low,high,A[low]};
    }else{
        int mid = (low+high)/2;
        MaxSub left = find_maximum_subarray(A,low,mid);
        MaxSub right = find_maximum_subarray(A,mid+1,high);
        MaxSub cross = find_max_crossing_subarray(A, low, mid, high);

        if (left.sum > right.sum && left.sum > cross.sum){
            return left;
        }else if (right.sum > left.sum && right.sum > cross.sum){
            return right;
        }else {
            return cross;
        }
    }
}


int main(){
    int n, A[100];
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for (int i=0; i<n; i++){
        cin>>A[i];
    }

    MaxSub max_sub = find_maximum_subarray(A,0, n-1);
    cout << "Index: [" << max_sub.left <<","<<max_sub.right<<"]\nMax Sum: "<<max_sub.sum<<endl;
}
