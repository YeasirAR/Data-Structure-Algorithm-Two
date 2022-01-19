#include<bits/stdc++.h>
using namespace std;

struct Act_Sel{
    int index;
    int start;
    int finish;
};
bool compare_to(Act_Sel c1, Act_Sel c2){
    return c1.finish<c2.finish;
}
vector<Act_Sel> activity_selection(int s[],int f[],int n){
    Act_Sel st[n];
    for(int i=0; i<n; i++){
        st[i].index=i;
        st[i].start=s[i];
        st[i].finish=f[i];
    }
    sort(st,st+n,compare_to);
    vector<Act_Sel> ret;
    ret.push_back(st[0]);
    for(int i=1,j=0; i<n; i++){
        if(st[i].start >= st[j].finish){
            ret.push_back(st[i]);
            j=i;
        }
    }
    return ret;
}

int main(){
    int start[]={2,3,8,7};
    int finish[]={8,4,1,1};
    int size = sizeof(start)/sizeof(start[0]);
    vector<Act_Sel> A = activity_selection(start,finish,size);
    for(Act_Sel s: A){
        cout << s.index << " "<< s.start << " "<<s.finish<<endl;
    }
}
