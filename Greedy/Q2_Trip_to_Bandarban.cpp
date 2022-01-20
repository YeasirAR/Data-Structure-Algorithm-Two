#include<bits/stdc++.h>
using namespace std;

struct Act_Sel{
    int start;
    int exit;
};
bool compare_to(Act_Sel c1, Act_Sel c2){
    return c1.exit<c2.exit;
}
vector<Act_Sel> activity_selection(int start[],int exit[],int n){
    Act_Sel st[n];
    for(int i=0; i<n; i++){
        st[i].start=start[i];
        st[i].exit=exit[i];
    }
    sort(st,st+n,compare_to);
    vector<Act_Sel> ret;
    ret.push_back(st[0]);
 
    for(int i=1,j=0; i<n; i++){
        if(st[i].start > st[j].exit){
            ret.push_back(st[i]);
            j=i;
        }
    }
    return ret;
}

int main(){
    int n;
    cin>>n;
    int start[n];
    int exit[n];
    for(int i=0; i<n; i++){
        int st,ex;
        cin>>st>>ex;
        start[i]=st;
        exit[i]=ex;
    }

    vector<Act_Sel> A = activity_selection(start,exit,n);
    if(A.size()==n){
        cout<<"Possible";
    }
    else{
        cout<<"Not Possible";
    }
}

/*
5
86202 86300
85369 86100
500 980
600 1000
40 80

5
40 90
1800 2000
1201 1400
800 1200
100 600
*/