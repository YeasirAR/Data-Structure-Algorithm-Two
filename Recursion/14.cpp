#include<iostream>
using namespace std;
int pal(string str,int start,int end,bool &isPal){
    if(start==start){
        return 0;
    }
    else{
        if(str[start]!=str[end]){
            isPal=false;
        }
        return pal(str,start+1,end-1,isPal);
    }
}

int main(){
    string str;
    cin>>str;
    bool isPal = true;
    pal(str,0,str.length()-1,isPal);
    if(isPal)
        cout<<"Palindrome";
    else
        cout<<"Not Palindrome";

    return 0;
}
