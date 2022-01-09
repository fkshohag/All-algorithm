# include <cstdio>
# include <iostream>
# define ll long long
using namespace std;
ll ncr(ll n,ll m)
{
    if(m>n-m)m=n-m;
    ll ans=1,i;
    for(i=0;i<m;i++)
    {
        ans=ans*(n-i)/(i+1);
    }
    return ans;
}
int main()
{
   int t;
   ll n,k;
   int cont=0;
   cin>>t;
   while(t--)
   {
       cin>>n>>k;
       cout<<ncr(n-1,k-1);
       cout<<endl;
   }
   return 0;
}
