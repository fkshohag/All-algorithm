# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
using namespace std;
vector<int>edge[100];
vector<int>redge[100];
vector<int>ans;
int node,nedge;
int vis[100];
int comp[100];
int inDegree[100];
int addEdge(int u,int v)
{
	edge[u].push_back(v);
	redge[v].push_back(u);
}
void dfs(int x)
{
    vis [x] = true;
    for ( size_t u = 0; u < edge [x].size(); u++ ) {
        if ( !vis [edge [x] [u]] )
            dfs(edge [x] [u]);
    }
    ans.push_back(x);
}
 
void rdfs(int x,int c)
{
    vis [x] = false;
    comp[x]=c;
    printf("%d",x);
    for ( size_t u = 0; u < redge [x].size(); u++ ) {
        if ( vis [redge[x] [u]] )
            rdfs(redge[x] [u], c);
    }
}
int main()
{
node=5;
nedge=5;
memset(vis,false,sizeof vis);
memset (inDegree, 0, sizeof inDegree);
for ( int i = 0; i <node; i++ ) {
    addEdge(1, 0);
    addEdge(0, 2);
    addEdge(2, 1);
    addEdge(0, 3);
    addEdge(3, 4);
    }
 
for ( int i = 0; i <node; i++ ) {
        if ( !vis [i] ) 
            dfs(i);
    }
int sub=0;
 for ( int i = ans.size() - 1; i >= 0; i-- ) {
        if ( vis[ans[i]] )
        {
         rdfs(ans [i], sub++);
          printf("\n");
        }
    }
   printf("number of Sub Group:%d\n",sub);
}
