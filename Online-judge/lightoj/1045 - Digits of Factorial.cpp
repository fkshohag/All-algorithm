# include <iostream>
# include <cstdio>
# include <cmath>
# define Max 1000001
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.text","r",stdin);
	#endif // ONLINE_JUDGE
	int t,c=0,a,b;
	double sum[Max];
	sum[0]=0;
	for(int i=1;i<Max;i++)sum[i]=sum[i-1]+log(i);
	scanf("%d",&t);
    while(t--)
    {
    	scanf("%d %d",&a,&b);
    	double res=1.0+sum[a]/log(b);
    	printf("Case %d: %d\n",++c,(int)res);
    }
    return 0;
}
