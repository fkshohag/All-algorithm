# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
int dp[100][100];
int lcs(string a,string b)
{
	int m=a.length();
	int n=a.length();
	int v=0;
	int longest=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]==b[j])
			{
				 v=dp[i][j]+1;
				dp[i+1][j+1]=v;
			}
			if(v>longest)
			{
				longest=v;
			}
		}
	}
	return longest;
}
int main()
{
	string a="alsdfkjfjkdsal";
	string b="fdjskalajfkdsla";
	cout<<lcs(a,b);
}
