#include <iostream>

using namespace std;

int main()
{
    int n;
    float sum=0,avg;
    cin>>n;
    for(int i=0; i<n; i++){
        float temp;
        cin>>temp;
        sum += temp;
    }
    avg = sum/n;
    cout << avg << endl;
    return 0;
}