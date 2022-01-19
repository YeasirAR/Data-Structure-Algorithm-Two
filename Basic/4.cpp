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
        int count=0;
        for(int j=0; j<n;j++){
            if(array[i]== array[j]){
                count++;
            }
        }
        bool flag=true;
        for(int j=i-1; j>=0; j--){
            if(array[i]==array[j])
                flag = false;
        }
        if(flag)
            cout<<array[i]<<" occurs "<<count<<" times"<<endl;
    }
    return 0;
}
