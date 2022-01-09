# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <queue>
# include <cstdlib>
# include <algorithm>
using namespace std;
# define inf 10000000;
# define cycle -33
class Graph
{
public:
	vector<int>edge[100];
	vector<int>cost[100];
	vector<int>ans;
	bool visited[100];
	Graph(){};
	void init();
	void AddEdge(int u,int v);
	void AddCost(int e,int cost);
	void Store(int node,int Edge);
	void bfs(int source,int distination);
	void dfs(int n);
public:
	int city,dist;
	bool operator<(const Graph &p)const
	{
		return dist>p.dist;
	}
	void dijkstra(int source,int distination);
	int Bellman_ford(int source,int distination,int node);
};
void Graph::init()
{
	memset(visited,false,sizeof visited);
}
void Graph::AddEdge(int u,int v)
{
	edge[u].push_back(v);
}
void Graph::AddCost(int e,int value)
{
	cost[e].push_back(value);
}
void Graph::Store(int node,int Edge)
{
	for(int i=0;i<Edge;i++)
	{
		int u,v,c;
		cin>>u>>v>>c;
		AddEdge(u,v);
		AddEdge(v,u);
		AddCost(u,c);
		AddCost(v,c);
	}
}
void Graph::bfs(int source,int distination)
{
	int d[100];
	queue<int>q;
	for(int i=0;i<100;i++)
	{
		d[i]=inf;
	}
	d[source]=0;
	q.push(source);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		int ucost=d[u];
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i];
			int vcost=cost[u][i]+ucost;
			if(d[v]>vcost)//relex
			{
				d[v]=vcost;
				q.push(v);
			}
		}
	}
	for(int i=0;i<=distination;i++)
	{
		printf("%d to %d distance %d\n",source,i,d[i]);
	}
}
void Graph::dfs(int n)
{
	visited[n]=true;
	for(int i=0;i<edge[n].size();i++)
	{
		int v=edge[n][i];
		if(!visited[v])
		{
			dfs(v);
		}
	}
	ans.push_back(n);
	return;
}
void Graph::dijkstra(int source,int distination)
{
	int d[100];
	priority_queue<Graph>q;
	Graph u,v;
	for(int i=0;i<100;i++)
	{
		d[i]=inf;
	}
	u.city=source;u.dist=0;
	d[u.city]=0;
	q.push(u);
	while(!q.empty())
	{
		u=q.top();q.pop();
		int ucost=d[u.city];
		for(int i=0;i<edge[u.city].size();i++)
		{
			v.city=edge[u.city][i];
			v.dist=cost[u.city][i]+ucost;
			if (d[v.city]>v.dist)//relex
			{
				d[v.city]=v.dist;
				q.push(v);
			}
		}
	}
	for(int i=0;i<=distination;i++)
	{
		printf("%d to %d distance %d\n",source,i,d[i]);
	}

}
int Graph::Bellman_ford(int source,int distination,int node)
{
	int d[100],p[100];//// d is for distance, p for predecessor 
	for(int i=0;i<100;i++)
	{
		d[i]=(i==source)?0:inf;
		p[i]=-1;
	}
	for(int k=0;k<node;k++)
	{
		bool done=1;
		for(int i=0;i<node;i++)
		{
			for(int j=0;j<edge[i].size();j++)
			{
				int u=i,uv=cost[u][j],v=edge[u][j];
				if (d[v]>uv+d[u])
				{
					d[v]=uv+d[u];
					p[v]=u;
					done=false;
				}
			}
		}
		if (done)
		{
			break;
		}
	}
	for(int k=0;k<node;k++)
	{
		for(int i=0;i<node;i++)
		{
			for(int j=0;j<edge[i].size();j++)
			{
				int u=i,v=edge[u][j],uv=cost[u][j]+d[u];
				if (d[v]>uv)
				{
					return cycle;
				}
			}
		}
	}
	return d[distination];
}
int main()
{
	Graph g;
	freopen("in","r",stdin);
	g.Store(5,8);
}
