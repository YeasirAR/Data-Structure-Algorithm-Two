#include<iostream>
#include<list>

using namespace std;

struct Graph{
	int num_vertex;
	list<int>* adjList;
	bool* visited; //color
	int* level;

	Graph(int vertices)
	{
		num_vertex = vertices;
		adjList = new list<int>[vertices];
	}

	void addEdge(int src, int dest)
	{
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}

	void BFS(int source_vertex)
	{
		visited = new bool[num_vertex];
		level = new int[num_vertex];

		for(int i=0; i<num_vertex; i++)
		{
			visited[i] = false;
			level[i] = 9999;
		}

		list<int> queue;
		list<int>::iterator i;

		visited[source_vertex] = true;
		level[source_vertex] = 0;
		queue.push_back(source_vertex);

		while(queue.empty()==false)
		{
			int curr_vertex = queue.front();
			queue.pop_front();
			cout << curr_vertex << "(" << level[curr_vertex] << "), ";

			for(i=adjList[curr_vertex].begin(); i!=adjList[curr_vertex].end(); i++)
			{
				int adj_vertex = *i;
				if(visited[adj_vertex]==false)
				{
					visited[adj_vertex] = true;
					level[adj_vertex] = level[curr_vertex] + 1;
					queue.push_back(adj_vertex);
				}
			}
		}
	}

	void DFS(int source_vertex)
	{
		visited = new bool[num_vertex];

		for(int i=0; i<num_vertex; i++)
		{
			visited[i] = false;
		}

		DFS_visit(source_vertex);
	}

	void DFS_visit(int source_vertex)
	{
		visited[source_vertex] = true;

		cout << source_vertex << " , " ;

		list<int>::iterator i;

		for(i=adjList[source_vertex].begin(); i!=adjList[source_vertex].end(); i++)
		{
			int adj_vertex = *i;
			if(visited[adj_vertex]==false)
			{
				DFS_visit(adj_vertex);
			}
		}

	}
};


int main()
{
	Graph *G = new Graph(4);

	G->addEdge(0,1);
	G->addEdge(1,2);
	G->addEdge(1,3);
	G->addEdge(2,3);

	G->BFS(0);



	return 0;
}
