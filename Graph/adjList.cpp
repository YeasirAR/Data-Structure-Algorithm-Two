#include<bits/stdc++.h>
using namespace std;
#define MAX_VERTICES 20
#define INF 99999

struct student{
    int course[5];
};
void Mark(){
    struct student marks[60];
    for(int i=0; i<60; i++){
        cin>>marks[i].course[0];
        cin>>marks[i].course[1];
        cin>>marks[i].course[2];
        cin>>marks[i].course[3];
        cin>>marks[i].course[4];
    }
}

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
    void DFS_Visit(int source);
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

    for(int i=0; i<num_vertices; i++){
        visited[i] = false;
        distance[i] = INF;
    }

    list<int> queue;

    visited[source] = true;
    distance[source] = 0;
    queue.push_back(source);
    cout <<"BFS: ";
    while(queue.empty()==false)
    {
        int curr_vertex = queue.front();
        queue.pop_front();
        cout << curr_vertex << " ";

    for(int i=0; i<adjacencyList[curr_vertex].size(); i++){
        int adj_vertex = adjacencyList[curr_vertex][i];
            if(visited[adj_vertex]==false){
                visited[adj_vertex] = true;
                distance[adj_vertex] = distance[curr_vertex] + 1;
                parent[adj_vertex]=curr_vertex;
                queue.push_back(adj_vertex);
            }
        }
    }
    cout<<endl;
}
void Graph:: DFS(int source){
    for(int i=0; i<num_vertices; i++){
		visited[i] = false;
	}
    cout<<"DFS: ";
	DFS_Visit(source);
    cout<<endl;
}

void Graph:: DFS_Visit(int source) {
	visited[source] = true;
	cout << source << " " ;
    for(int i=0; i<adjacencyList[source].size(); i++){
        int adj_vertex = adjacencyList[source][i];
        if(visited[adj_vertex] == false){
            parent[adj_vertex]=source;
			DFS_Visit(adj_vertex);
		}
	}
}

void Graph:: printParentTree(){
    cout<<"Tree: "<<endl;
    for(int i=0; i<num_vertices; i++){
        cout<<i<<": ";
        for(int j=0; j<adjacencyList[i].size(); j++){
            int adj_vertex = adjacencyList[i][j];
            cout<<adj_vertex<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Graph g1, g2;
    g1.is_directed=true;
    g1.num_vertices=6;

    g2.is_directed=false;
    g2.num_vertices=8;

    g1.AddEdge(0,1);
    g1.AddEdge(1,2);
    g1.AddEdge(1,3);
    g1.AddEdge(2,3);
    g1.AddEdge(2,4);
    g1.AddEdge(4,5);
    g1.AddEdge(3,5);
    g1.BFS(0);
    g1.DFS(0);
    g1.printParentTree();

    return 0;
}
