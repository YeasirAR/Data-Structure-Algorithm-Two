#include <iostream>
using namespace std;

/*#define P_INF 99999
#define N_INF -99999

struct MinMax{
    int min;
    int max;
};
*/

int Rec_Max(int array[], int n,int max){
    if(n<1){
        return max;
    }
    else{
        if(max<array[n-1]){
            max = array[n-1];
        }
        return Rec_Max(array,n-1,max);
    }
}
int Rec_Min(int array[], int n,int min){
    if(n<1){
        return min;
    }
    else{
        if(min>array[n-1]){
            min = array[n-1];
        }
        return Rec_Min(array,n-1,min);
    }
}


int main(){
    int n, A[100];
    int max=-9999;
    int min=9999;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for (int i=0; i<n; i++){
        cin>>A[i];
    }
	cout << "Max: " << Rec_Max(A, n,max)<<endl;
	cout << "Min: " << Rec_Min(A, n,min)<<endl;
	return 0;
}
