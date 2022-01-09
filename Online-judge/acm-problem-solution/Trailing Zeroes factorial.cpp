# include <iostream>
# include <cstdio>
# define ll long long
using namespace std;
ll zero_count(ll n)
{
	ll p=5,cont=0;
	while(p<=n)
	{
		cont+=n/p;
		p*=5;
	}
	return cont;
}
int main()
{
	//freopen("in.text","r",stdin);
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<zero_count(n)<<endl;
	}
	return 0;
}
