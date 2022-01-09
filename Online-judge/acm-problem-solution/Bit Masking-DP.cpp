# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
int n;
int dp[(1<<15)+2];
int w[20][20];
inline int Set(int N,int pos){return N=N|(1<<pos);}//bit set pos-th position in N
inline int Reset(int N,int pos){return N=N&~(1<<pos);}//bit rset pos-th position in N
inline bool Check(int N,int pos){return(bool)(N&(1<<pos));}//check set or reset?
int call(int mask)
{
    if(mask==(1<<n)-1)return 0;//check all of mask value i set by 1 or not?if set all than taken 0
    if(dp[mask]!=-1)return dp[mask];//if already we take mask value than not taken now
    int ans=1<<28;//infinity value
    for(int i=0;i<n;i++)
        if(Check(mask,i)==0)
        {
            int price=w[i][i];//the cost of i-th value
            for(int j=0;j<n;j++)
                if(i!=j and Check(mask,j)!=0)//if i!=j and j already taken
                    price+=w[i][j];//than price+w[i][j]
            int ret=price+call(Set(mask,i));//taken another value and check
            ans=min(ans,ret);//if is it minimum or maximum
        }
    return dp[mask]=ans;
}
int main()
{
    memset(dp,-1,sizeof dp);//set dp by-1
cin>>n;//n-th is our total value
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>w[i][j];//taken value
int ret=call(0);//first we take 0-th value
printf("the result is=%d",ret);
return 0;
}
