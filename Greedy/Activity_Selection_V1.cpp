#include<bits/stdc++.h>
using namespace std;

struct Act_Sel{
    int index;
    int start;
    int finish;
    char ch;
};
bool compare_to(Act_Sel c1, Act_Sel c2){
    return c1.finish<c2.finish;
}
vector<Act_Sel> Activity_Selection(int s[],int f[],int n,char ch[]){
    Act_Sel st[n];
    for(int i=0; i<n; i++){
        st[i].index=i;
        st[i].start=s[i];
        st[i].finish=f[i];
        st[i].ch=ch[i];
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
    int x;
    char ch[100];
    int start[100];
    int finish[100];
    cin>>x;
    for(int i=0;i<x;i++){
        cin>>ch[i]>>start[i]>>finish[i];
        finish[i]+=start[i];
    }
    vector<Act_Sel> A = Activity_Selection(start,finish,x,ch);
    for(Act_Sel s: A){
        cout <<s.ch<<endl;
    }
}
