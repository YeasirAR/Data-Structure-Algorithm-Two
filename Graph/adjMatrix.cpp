#include<bits/stdc++.h>
#define MAX_VERTICES 20

class Graph{
    int matrix[MAX_VERTICES][MAX_VERTICES];
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

int main()
{
    Graph g1, g2;
    // g1.is_directed=true;
    // g1.num_vertices=10;

    // g2.is_directed=false;
    // g2.num_vertices=8;

    return 0;
}