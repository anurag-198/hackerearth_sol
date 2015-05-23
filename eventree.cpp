#include <iostream>
#include <stdio.h>
#include <cstring>
#include <list>
#define ll long long

using namespace std;

int flag, ans, count;
int dist[102];

class Graph
{
	int V;
	list<int> *adj;
	void DFSUtil(int v,bool visited[]);
public:
	Graph(int V);
	void add_edge(int v,int w);
	void DFS(int v);
	int BFS(int v);
	int chil(int v, bool visited[]);
};

Graph::Graph(int V)
{
	this->V=V;
	adj = new list<int>[V];
}


void Graph::add_edge(int v,int w)
{
	//adj[w].push_back(v);
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v,bool visited[])
{
	if (flag == 1) {
		return;
	}

	visited[v]=true;
	//printf("%d ",(v+1));	
	list<int>::iterator i;
	for(i=adj[v].begin();i != adj[v].end(); ++i)
	{
	//	cout <<"hey";
		if(!visited[*i]) {
	//		cout << *i << endl;
			DFSUtil(*i,visited);
		}
		else {
	//		cout << *i << endl;
			flag = 1;
			return;
		}
	}
}

void Graph::DFS(int v)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;

	DFSUtil(v,visited);	
}

int Graph::chil(int v, bool visited[]) {
	int sum = 0;
	list<int>::iterator it;
	
	visited[v] = true;

	if (adj[v].size() == 0) {
		dist[v] = 1;
	}
	else if (dist[v] == 0) {
		for (it = adj[v].begin();it != adj[v].end();it++) {
			if (!visited[*it])
				sum += chil(*it, visited);
		}
	}

	dist[v] = sum + 1;
	//cout << dist[v] << endl;
	return dist[v];
}

int Graph::BFS(int v)
{	
	int t;
	bool *visited = new bool[V];
	
	list<int> queue;
	
	int dist[V], maxx, nd;
	memset(dist, 1, sizeof(dist));

	visited[v]=true;
	queue.push_back(v);

	list<int>::iterator i;

	while(!queue.empty())
	{
		
		v=queue.front();
		dist[v] += adj[v].size();
		queue.pop_front();
		
		for(i=adj[v].begin(); i != adj[v].end(); i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				dist[v] += dist[*i];
				queue.push_back(*i);
			}
		}
	}

	maxx = dist[0];
	nd = 0;
	for (int i = 0; i < V; i++) {
		if (dist[i] > maxx) {
			maxx = dist[i];
			nd = i;
		}
	}
	ans = dist[nd];
	return nd;
}

int main()
{
	int n1,n2,t,n,j,i,m,k,a,v,c=0,Q, a1, b1;
//	scanf("%d",&t);

	scanf ("%d%d", &n, &m);
	
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
		visited[i]=false;
	
	
	Graph g(n);

	for (i = 0;i < m; i++) {
		scanf ("%d%d", &a1,&b1);
		g.add_edge(a1 - 1,b1 - 1);
		g.add_edge(b1 - 1, a1 - 1);
	}

	//n1 = g.BFS(0);
	n1 = g.chil(0, visited);
	
	for(i = 0; i < n; i++) {
		if (dist[i] % 2 == 0) 
			ans++;
	}

	cout << ans - 1 << endl;
	//n2 = g.BFS1(0);

	/*for (i = 0; i < n; i++) {
		cout << dist[i] << endl;
	}*/
	//printf ("%d\n", ans);
	return 0;
}