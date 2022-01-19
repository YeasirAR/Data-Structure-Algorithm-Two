#include<bits/stdc++.h>
#define WHITE 1
#define GREY 2
#define BLACK 3
using namespace std;

vector<int> color;
vector<int> order;
bool isCycle=false;


void DFS_Visit(vector<int> adjList[], int u) {
    color[u] = GREY;
    for(int v=0; v<adjList[u].size(); v++) {
        if(color[adjList[u][v]] == WHITE) {
            DFS_Visit(adjList,adjList[u][v]);
        }
        if(color[adjList[u][v]] == GREY) {
            isCycle=true;
        }
    }
    color[u] = BLACK;
    order.push_back(u);
}

void DFS(int V,vector<int> adjList[]){
    for(int i=0; i<V; i++) {
        color.push_back(WHITE);
    }

    for(int i=0; i<V; i++) {
        if(color[i] == WHITE) {
            DFS_Visit(adjList,i);
        }
    }
}


int main(){

    int vertices, edges;
    cin >> vertices >> edges;
    vector< int > adjList[vertices];
    for(int i=0;i<edges;i++){
        int source, destination;
        cin >> source >> destination;
        adjList[source].push_back(destination);
    }

    DFS(vertices,adjList);

    if(!isCycle){
        cout<<"Topological Order: ";
        for(int i=order.size()-1; i>=0; i--){
            cout<<order[i]<<" ";
        }
    }
    else{
        cout<<"Not a Directed Acyclic Graph";
    }

    return 0;
}

/*
Sample Inputs

5 6
0 3
1 0
1 2
2 3
2 4
3 4


5 6
0 3
1 0
1 2
2 3
4 2
3 4

8 13
0 1
0 5
0 4
1 2
1 3
3 2
4 3
4 5
5 3
6 5
6 7
6 4
7 3

*/

