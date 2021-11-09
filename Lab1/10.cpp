#include<iostream>
#include<algorithm>

using namespace std;

struct StructTest{
    string firstname;
    string lastname;
    int id;
    int salary;
};
bool sortst(StructTest s1, StructTest s2){
    if(s1.salary<s2.salary)
        return true;
    if(s1.salary>s2.salary)
        return false;
    if(s1.salary==s2.salary){
        if(s1.id<s2.id)
            return true;
        if(s1.id>s2.id)
            return false;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    struct StructTest st[n];
    for(int i=0; i<n; i++){
        cin>>st[i].firstname;
        cin>>st[i].lastname;
    }
    for(int i=0; i<n; i++){
        cin>>st[i].id;
    }
    for(int i=0; i<n; i++){
        cin>>st[i].salary;
    }

    sort(st,st+n,sortst);

    for(int i=0; i<n; i++){
        cout<<st[i].firstname<<" ";
        cout<<st[i].lastname<<" ";
        cout<<st[i].salary<<" ";
        cout<<st[i].id<<endl;
    }


}
