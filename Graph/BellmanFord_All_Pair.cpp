#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
};
const int INF = 0x7f7f7f7f;
int dist[107];
int parent[107];

bool relax(int u, int v, int w)
{
    if(dist[v]>dist[u]+w)
    {
        dist[v] = dist[u] + w;
        parent[v]=u;
        return true;
    }
    else
        return false;
}
void BellmanFord(int source, int V, vector< edge > adjacentList)
{
    for(int i=0;i<V;i++)
        dist[i] = INF;
    dist[source] = 0;
    parent[source]=-1;

    for(int i=1;i<=V-1;i++)
    {
        for(edge e : adjacentList)
        {
            relax(e.u, e.v, e.w);
        }
    }

    for(edge e : adjacentList)
    {
        if(relax(e.u, e.v, e.w))
        {
            cout << "Negative Cycle Detected!!\n";
            return;
        }
    }
}
void Print_Path(int parent[] , int  vertex){
    if(parent[vertex]==-1){
        cout<<vertex;
        return;
    }
    Print_Path(parent ,   parent[vertex]);
    cout<<"-->"<<vertex;

}
int main()
{
    //freopen("input.txt","r",stdin);
    int vertices, edges; cin >> vertices >> edges;
    vector< edge > adjacentList;
    for(int i=0;i<edges;i++)
    {
        edge e;
        cin >> e.u >> e.v >> e.w;
        adjacentList.push_back(e);
    }
    //int parent[adjacentList.size()+1];
    for(int source=0;source<vertices;source++){
        BellmanFord(source, vertices, adjacentList);
        for(int i=0;i<vertices;i++){
            if(dist[i] == INF){
                cout << source<<" - " << i << " : " <<"     No Path"<<endl;
                continue;
            }
            cout << source<<" - " << i << " : " << dist[i] << "    ";
            Print_Path(parent, i);
            cout<<endl;
        }
        cout<<endl;
    }
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
*/