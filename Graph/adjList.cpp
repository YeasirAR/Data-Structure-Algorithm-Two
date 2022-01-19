#include<bits/stdc++.h>
using namespace std;
#define MAX_VERTICES 20

class Graph{
    public:
    vector<int> adjacencyList[MAX_VERTICES];
    int num_vertices;
    bool is_directed;

    bool visited[MAX_VERTICES];
    int parent[MAX_VERTICES];
    int distance[MAX_VERTICES];

    void AddEdge(int u,int v);
    void RemoveEdge(int u,int v);
    void BFS(int source);
    void DFS(int source);
    int getDistance(int s,int d);
    void printParentTree();
};

void Graph:: AddEdge(int u,int v){
    adjacencyList[u].push_back(v);
    if(!is_directed){
        adjacencyList[v].push_back(u);
    }
}
void Graph:: RemoveEdge(int u,int v){
    for (int i = 0; i < adjacencyList[u].size(); i++) {
        if (adjacencyList[u][i] == v) {
            adjacencyList[u].erase(adjacencyList[u].begin() + i);
            break;
        }
    }

    for (int i = 0; i < adjacencyList[v].size(); i++) {
        if (adjacencyList[v][i] == u) {
            adjacencyList[v].erase(adjacencyList[v].begin() + i);
            break;
        }
    }
}
void Graph:: BFS(int source){
    visited[source] = false;

    queue< int > Q;
    Q.push(source);
    distance[source]=0;

    while(!Q.empty())
    {
        int visiting_node = Q.front();
        Q.pop();
        if(visited[visiting_node]==true)
            continue;

        for(int i=0; i<adjacencyList[visiting_node].size(); i++){
            int child = adjacencyList[visiting_node][i];
            if(visited[child]==false){
                Q.push(child);
                distance[child]=distance[visiting_node]+1;
            }
        }
        visited[visiting_node] = true;
        cout << visiting_node << " ";
    }
}
void Graph:: DFS(int source){
    visited[source] = true;
    cout<<source<<" ";
    for(int v=0; v<adjacencyList[source].size(); v++) {
        if(visited[v] == false) {
            parent[v]=source;
            DFS(adjacencyList[source][v]);
        }
    }
}
void Graph:: printParentTree(){
//   for (int i = 0; i < num_vertices; i++) {
//     cout << "\n Vertex " << i << ":";
//     for (auto x : adjacencyList[i])
//         cout << "-> " << x;
//     cout<<endl;
//   }
}

int main()
{
    Graph g1, g2;
    g1.is_directed=true;
    g1.num_vertices=10;

    g2.is_directed=false;
    g2.num_vertices=8;

    return 0;
}
