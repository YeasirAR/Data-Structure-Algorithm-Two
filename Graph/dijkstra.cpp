#include<iostream>
#include<map>
#include<vector>
#include<queue>
#define SIZE 107
using namespace std;
int dist[SIZE];
const int INF = 0x7f7f7f7f;

void dijkstra(int source, map< int , vector< pair< int , int > > > adjacentList, int parent[])
{
    for(int i=0;i<SIZE;i++) dist[i] = INF;
    dist[source] = 0;

    // weight, vertex
    priority_queue< pair< int , int > , vector< pair< int , int > > , greater< pair< int , int >> > pq;
    pq.push({0,source});
    parent[source]=-1;

    while(!pq.empty())
    {
        pair< int , int > top = pq.top();
        pq.pop();
        int u = top.second;


        for(pair< int , int > &v : adjacentList[u])
        {
            /**v.first -> node
            v.second -> cost**/

            int destination_node = v.first;
            int cost_uv = v.second;

            if(dist[destination_node]>dist[u]+cost_uv)
            {
                dist[destination_node] = dist[u] + cost_uv;
                pq.push({dist[destination_node],destination_node});
                parent[destination_node]=u;
            }
        }
    }
    return;

}
void printsoutce(int parent[] , int  vertex){
    if(parent[vertex]==-1){
        cout<<vertex;
        return;
    }
    printsoutce(parent ,   parent[vertex]);
    cout<<"-->"<<vertex;

}

int main()
{
    //freopen("input.txt","r",stdin);
    int vertices, edges; cin >> vertices >> edges;
    map< int , vector< pair< int , int > > > adjacentList;

    for(int i=0;i<edges;i++)
    {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        adjacentList[source].push_back({destination,weight});
    }

    /**
    for(pair< int , vector< pair< int , int > > > key_value_pair : adjacentList)
    {
        cout << key_value_pair.first << " --> ";
        for(pair< int , int > &value : key_value_pair.second)
        {
            cout << "( " << value.first << " , " << value.second << ") ";
        }
        cout << "\n";
    }
    **/
    int parent[adjacentList.size()+1];
    int source = 1;
    dijkstra(source,adjacentList,parent);
    for(int i=0;i<vertices;i++){
        if(dist[i] == INF){
            cout << source<<" - " << i << " : " <<"     No Path"<<endl;
            continue;
        }
        cout << source<<" - " << i << " : " << dist[i] << "    ";
        printsoutce(parent, i);
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