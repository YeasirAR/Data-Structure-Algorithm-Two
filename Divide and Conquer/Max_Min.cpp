#include<iostream>
using namespace std;

struct MN{
    int fmax;
    int fmin;
};


MN RMaxMin(int arr[], int i, int j){

    if (i==j){
        struct MN x;
        x.fmax = arr[i];
        x.fmin = arr[i];
        return x;
    } else {
        struct MN g;
        struct MN h;
        int mid = (i+j)/2;
        g = RMaxMin(arr, i, mid);
        h = RMaxMin(arr, mid+1, j);
        int fmax = max(g.fmax,h.fmax);
        int fmin = min(g.fmin,h.fmin);
        return {fmax,fmin};
    }
}


int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  struct MN x;
  x=RMaxMin(arr, 0, size - 1);
  cout<<"Max: "<<x.fmax<<"\nMin: "<<x.fmin;

  return 0;
}
