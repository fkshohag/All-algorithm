# include <iostream>
# include <cstdio>
# include <cstring>
# define size 10000
using namespace std;
int f[size];
int BIT[size];
int maxidx;
int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=BIT[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
int update(int idx,int val)
{
    while(idx<=maxidx)
    {
        BIT[idx]+=val;
        idx+=(idx&-idx);
    }
}
int quare(int i,int j)
{
    return read(j)-read(i-1);
}
int main()
{
   //freopen("in.text","r",stdin);
    memset(BIT,0,sizeof BIT);
    int n=10;
    maxidx=n;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i];
        update(i,f[i]);
    }
    cout<<"Original Array"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<f[i]<<" ";

    }
    cout<<endl<<endl;
    cout<<"BIT Array sotre data"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<BIT[i]<<" ";

    }
    cout<<endl<<endl;
    cout<<"Sum of every index"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<read(i)<<" ";
    }
    cout<<endl<<endl;
    cout<<"i to j Index sum"<<endl;
    cout<<quare(2,3);
  return 0;
}
