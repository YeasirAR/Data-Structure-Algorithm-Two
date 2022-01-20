#include<bits/stdc++.h>
using namespace std;

struct Act_Sel{
    string name;
    int start;
    int finish;
};
bool compare_to(Act_Sel c1, Act_Sel c2){
    return c1.finish-c1.start<c2.finish-c2.start; //something is wrong here
}
vector<Act_Sel> activity_selection(string name[],int start[],int finish[],int n,int x){
    Act_Sel st[n];
    for(int i=0; i<n; i++){
        st[i].name=name[i];
        st[i].start=start[i];
        st[i].finish=finish[i];
    }
    sort(st,st+n,compare_to);
    vector<Act_Sel> ret;
    ret.push_back(st[0]);
 
    for(int i=1,j=0; i<n; i++){
        int prev_finish=st[j].finish;
        if(i%2==0){
            prev_finish+=x;
        }
        if(st[i].start >= prev_finish){
            ret.push_back(st[i]);
            j=i;
        }
    }
    return ret;
}

int main(){
    int n,x;
    cin>>n;
    string name[n];
    int start[n];
    int finish[n];
    for(int i=0; i<n; i++){
        string na;int st,dur;
        cin>>na>>st>>dur;
        name[i]=na;
        start[i]=st;
        finish[i]=st+dur;
    }
    cin>>x;

    vector<Act_Sel> A = activity_selection(name,start,finish,n,x);
    for(Act_Sel s: A){
        cout << s.name << endl;
    }
}

/*
4         
a 2 8
b 3 4
d 8 1
c 7 1
1

expected output:
b
d
*/