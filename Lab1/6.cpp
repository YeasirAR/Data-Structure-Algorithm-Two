#include <iostream>

using namespace std;
void reverse_array(int arr[], int n);
void print_array(int arr[], int n);

int main()
{
    int n;
    int array[100];

    cout<<"Enter Array Size"<<endl;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>array[i];
    }
    reverse_array(array,n);
    print_array(array,n);
    return 0;
}
void reverse_array(int* array, int n){
    for(int i=0; i<n; i++){
        int temp = array[i];
        array[i]=array[n-i-1];
        array[n-i-1]=temp;
        if(i==(n-i-1)){
            break;
        }
    }
}
void print_array(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}