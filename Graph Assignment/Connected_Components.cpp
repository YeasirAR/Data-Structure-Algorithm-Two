#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int a,b;
};

struct Graph{
    int V;
    vector<Edge> edges;
};

void make_set(int parent[],int x){
    parent[x]=x;
}

int find_set(int parent[],int x){
    if(x!=parent[x]){
        return find_set(parent,parent[x]);
    }
    return parent[x];
}

void _union(int parent[],int x, int y){
    int a = find_set(parent,x);
    int b = find_set(parent,y);
    parent[a]=b;
}
void connected_components(Graph g,int parent[]){
    for(int i=0; i<g.V; i++){
        make_set(parent,i);
    }
    for(Edge edge: g.edges){
        if(find_set(parent,edge.a)!=find_set(parent,edge.b)){
            _union(parent,edge.a,edge.b);
        }
    }
    map<int,vector<int> > all_component;

    for(int i=0 ;i<g.V; i++){
        int representative= find_set(parent,i);
        all_component[representative].push_back(i);
    }
    cout<<endl;
    int i=1;
    for(auto component : all_component ){
        cout<<"Connected Component "<<i<<": ";
        for(int vertex: component.second){
            cout<<vertex<<" ";
        }
        i++;
        cout<<endl;
    }
    cout<<"Total Connected Components: "<<i-1<<endl;
}


int main(){
    int V, E;
    cin>>V>>E;
    vector<Edge> edges;
    for(int i=0; i<E; i++){
        int a, b;
        cin>>a>>b;
        edges.push_back({a,b});
    }
    Graph graph = {V,edges};
    int parent[graph.V];
    connected_components(graph,parent);
}
/*

12 13
0 3
1 0
1 2
2 3
2 4
3 4
6 7
5 6
5 7
9 8
9 10
10 11
8 11


*/
