#include <iostream>

using namespace std;

int main()
{
    int n;
    int array[100];

    cout<<"Enter Array Size"<<endl;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>array[i];
    }
    for(int i=0; i<n; i++){
        bool found = false;
        for(int j=0; j<i;j++){
            if(array[i] == array[j]){
                found = true;
            }
        }
        if(found == false){
            cout<<array[i]<<" ";
        }
    }
    return 0;
}