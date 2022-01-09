# include <iostream>
# include <cstdio>
# include <set>
using namespace std;
int main()
{
	freopen("in", "r", stdin); 
	freopen("out", "w", stdout);
	int t,cas=0;
	cin>>t;
	while(t--)
	{
		int gird1[5][5],gird2[5][5];
	int first,second;
		cin>>first;
		printf("Case #%d: ",++cas);
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
				cin>>gird1[i][j];
			}
		}
		cin>>second;
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
				cin>>gird2[i][j];
			}
		}
		set<int>posibility;
		set <int> possibleCards;
		for (int j = 1; j <= 4; j++)
			for (int jj = 1; jj <= 4; jj++)
				if (gird1[first][j] == gird2[second][jj])
					posibility.insert(gird1[first][j]);
		if(posibility.empty())
		{
			printf("Volunteer cheated!\n");
		}
		else
		{
			if(posibility.size()>1)
			{
				printf("Bad magician!\n");
			}
			else
			{
				 printf("%d\n", *posibility.begin());
			}
		}
		
	}
	return 0;
}
