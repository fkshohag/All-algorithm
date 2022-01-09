# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
int main()
{
	//freopen("in.text","r",stdin);
	int m,n,ans,t,c=0;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d %d",&m,&n);
		if(m==1)ans=n;
		else if(n==1)ans=m;
		else if(m==2)
		{
			ans=(n/4)*4;
			if(n%4==1)ans+=2;
			else if(n%4>1)ans+=4;
		}
		else if (n==2)
		{
			ans=(m/4)*4;
			if(m%4==1)ans+=2;
			else if(m%4>1)ans+=4;
		}
		else
		{
			ans=((m*n)+1)/2;
		}
		printf("Case %d: %d\n",++c,ans);
	}
	return 0;
}
