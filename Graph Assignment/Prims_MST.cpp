#include<bits/stdc++.h>
using namespace std;

#define INF 99999
#define NIL -1

struct Edge{
    int source, destination, weight;
};

struct pair_node{
    int a, b;
};

struct compare_to{
    bool operator()(pair_node node1, pair_node node2){
        return node1.b>node2.b;
    }
};

void prims_mst(vector<Edge> adjacentList[], int V, int source){
    int popped[V];
    int key[V];
    int p[V];
    for(int i=0;i<V;i++){
        popped[i]=0;
        key[i]=INF;
        p[i]=NIL;
    }
    priority_queue<pair_node,vector<pair_node>,compare_to> pq;
    key[source]=0;
    pq.push({source,key[source]});

    while(!pq.empty()){
        pair_node u_node =pq.top();
        pq.pop();
        int u = u_node.a;
        popped[u]=1;
        for(Edge e:adjacentList[u]){
            int v=e.destination;
            if(popped[v]!=1 && e.weight<key[v]){
                p[v]=u;
                key[v]=e.weight;
                pq.push({v,key[v]});
            }
        }
    }

    cout<<endl<<"Minimum Spanning Tree:"<<endl;
    for(int i=0; i<V; i++){
        if(p[i]!=NIL){
            cout<<p[i]<<"  ---  "<<i<<"   :   "<<key[i]<<endl;
        }
    }
}

int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    vector<Edge> adjacentList[vertices];
    for(int i=0; i<edges;i++){
        int source, destination, weight;
        cin>>source>>destination>>weight;
        adjacentList[source].push_back({source,destination,weight});
    }
    prims_mst(adjacentList,vertices,0);

    return 0;
}
/*

5 7
0 1 2
0 2 5
1 2 2
1 3 7
2 3 2
2 4 5
3 4 1


9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

*/
