#include<bits/stdc++.h>
using namespace std;
#define in(x) cin>>x
#define out(x) cout<<x

class disjoint_set {
    vector<int> v;
    int sz;
public:
    disjoint_set(int n) {
        makeset(n);
    }

    void makeset(int n) {
        v.resize(n);
        iota(v.begin(), v.end(), 0);
        sz = n;
    }

    int find(int i) {
        if (i != v[i])
            v[i] = find(v[i]);
        return v[i];
    }

    void join(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri != rj) {
            v[ri] = rj;
            sz--;
        }
    }

    int size() {
        return sz;
    }


    //connected components;

    void allConnectedComponents(){
        unordered_map<int,vector<int> > root_to_component;

        for(int i=0 ;i<v.size(); i++){
            int root= find(i);
            root_to_component[root].push_back(i);
        }

        for(auto components : root_to_component ){
            for(int i: components.second){
                out(i<<" ");
            }
            out("\n");
        }


    }

};



int main(){
    ios_base::sync_with_stdio(false);

    disjoint_set disjSet(8);
    disjSet.join(0,3);
    disjSet.join(1,0);
    disjSet.join(1,2);
    disjSet.join(2,3);
    disjSet.join(2,4);
    disjSet.join(3,4);
    disjSet.join(6,7);
    disjSet.join(5,6);
    disjSet.join(5,7);

    disjSet.allConnectedComponents();



    return 0;
}
