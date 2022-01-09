# include <iostream>
# include <cstdio>
# include <cstdlib>
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0)return b;
    gcd(b,a%b);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.text","r",stdin);
    #endif // ONLINE_JUDGE
    int t,i,total,c=0;
    cin>>t;
    while(t--)
    {
        total=0;
        int n;
        cin>>n;
        int key=n;
        for(i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x>0)
            {
                total+=x;
            }
            else
            {
                total-=x;
                key--;
            }
        }
        if(!key)
        {
            printf("Case %d: inf\n",++c);
        }
        else
        {
            int k=gcd(total,key);
            printf("Case %d: %d/%d\n",++c,total/k,key/k);
        }
    }
    return 0;
}
