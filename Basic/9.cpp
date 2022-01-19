#include<iostream>
#include<algorithm>

using namespace std;

struct StructTest{
    string firstname;
    string lastname;
    int height;
    int age;
};
bool sortst(StructTest s1, StructTest s2){
    if(s1.height<s2.height)
        return false;
    if(s1.height>s2.height)
        return true;
    if(s1.height==s2.height){
        if(s1.age<s2.age)
            return false;
        if(s1.age>s2.age)
            return true;
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
        cin>>st[i].height;
        cin>>st[i].age;
    }
    sort(st,st+n,sortst);
    for(int i=0; i<n; i++){
        cout<<st[i].firstname<<" ";
        cout<<st[i].lastname<<" ";
        cout<<st[i].height<<" ";
        cout<<st[i].age<<endl;
    }


}
