# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
int dp[50][50];
int lcs(string a,string b,int m,int n)
{
	if(m==0 or n==0)return 0;
	if(dp[m][n]!=-1)return dp[m][n];
	if(a[m]==b[n])dp[m][n]=lcs(a,b,m-1,n-1)+1;
	else
		dp[m][n]=max(lcs(a,b,m-1,n),lcs(a,b,m,n-1));
	return dp[m][n];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	string a="adc";
	string b="abc";
	cout<<lcs(a,b,a.length(),b.length());
}
