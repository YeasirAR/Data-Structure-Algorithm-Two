#include<iostream>
using namespace std;


void Rmaxmin(int A[], int i, int j, int& fmax, int& fmin){
    if (i==j){
        fmax = A[i];
        fmin = A[i];
    } else if (i==j-1){
        if (A[i]<A[j]){
            fmax = A[j];
            fmin = A[i];
        }else{
            fmax = A[i];
            fmin = A[j];
        }
    } else {
        int mid = (i+j)/2;
        int gmax, gmin, hmax, hmin;
        Rmaxmin(A, i, mid, gmax, gmin);
        Rmaxmin(A, mid+1, j, hmax, hmin);
        fmax = (gmax > hmax) ? gmax : hmax ;
        fmin = (gmin < hmin) ? gmin : hmin;
    }
}

void change_me(int* a){
    *a = 10;
}

void change_me_cpp(int& a){
    a = 99;
}

int main(){
//    int a = 55;
//    change_me(&a);
//    change_me_cpp(a);
//    cout << a;
    int arr[100];
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> arr[i];

    cout << "Array ";
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";

    int fmax, fmin;
    Rmaxmin(arr, 0, n-1, fmax, fmin);

    cout << "max: " << fmax << ", min: "<< fmin <<"\n";
}
