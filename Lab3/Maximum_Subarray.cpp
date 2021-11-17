#include<iostream>
using namespace std;

#define NEG_INFTY -999999

class Result{
public:
    int l, r, sum;
};

Result find_max_crossing_subarray(int A[], int low, int mid, int high){
    int left_sum = NEG_INFTY, max_left;
    int sum = 0;
    for (int i=mid; i>=low;i--){
        sum += A[i];
        if (sum>left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = NEG_INFTY, max_right;
    sum = 0;
    for (int i=mid+1; i<=high;i++){
        sum += A[i];
        if (sum>right_sum){
            right_sum = sum;
            max_right = i;
        }
    }

    Result res;
    res.l = max_left;
    res.r = max_right;
    res.sum = left_sum + right_sum;
    return res;
}

Result find_maximum_subarray(int A[], int low, int high){
    if (high == low){
        Result res;
        res.l = low;
        res.r = high;
        res.sum = A[low];
        return res;
    }else{
        int mid = (low+high)/2;
        Result left = find_maximum_subarray(A,low,mid);
        Result right = find_maximum_subarray(A,mid+1,high);

        Result cross = find_max_crossing_subarray(A, low, mid, high);

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
//    Result res;
//    res.l = 1;
//    res.r = 2;
//    res.sum = 3;
//    cout << res.l << res.r << res.sum;

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

    Result res = find_maximum_subarray(arr,0, n-1);
    cout << "[" << res.l <<","<<res.r<<"]: "<<res.sum <<"\n";
}
