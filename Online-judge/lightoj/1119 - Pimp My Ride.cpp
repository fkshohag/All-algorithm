# include <cstdio>
# include <cstring>
# include <iostream>
using namespace std;
# define rep(i,n)for(int (i)=0;i<(n);i++)
# define si(x)scanf("%d",&(x))
int dp[(1<<15)+2];
int w[20][20];
int n;
inline bool check(int mask,int pos){return(bool)(mask&(1<<pos));}
inline int Reset(int mask,int pos){return mask=mask&~(1<<pos);}
inline int Set(int mask,int pos){return mask=mask|(1<<pos);}
int solve(int mask)
{
	if(mask==(1<<n)-1)return 0;
	if(dp[mask]!=-1)return dp[mask];
	int minimum=1<<28;
	rep(i,n)
	if (check(mask,i)==0)
	{
		int price=w[i][i];
		rep(j,n)
		if(i!=j && check(mask,j)!=0)price+=w[i][j];
		int ret=price+solve(Set(mask,i));
		minimum=min(ret,minimum);
	}
	return dp[mask]=minimum;
}
int main()
{
	//freopen("in","r",stdin);
	int test;
	int cont=0;
	si(test);
	while(test--)
	{
		memset(dp,-1,sizeof dp);
		si(n);
		rep(i,n)
		rep(j,n)
		si(w[i][j]);
		int mask=0;
		int ret=solve(mask);
		printf("Case %d: %d\n",++cont,ret);
	}
	return 0;
}
