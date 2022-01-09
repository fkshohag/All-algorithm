# include <iostream>
# include <cstdio>
using namespace std;
int main()
{
	string s="baab";
	int n=s.size();
	bool flag=true;
	for(int i=0;i<n/2;++i)
	{
		if(s[i]!=s[n-i-1])
			flag=false;
	}
	if(flag)
		cout<<"palindrome"<<"\n";
	else
		cout<<"not palindrome"<<"\n";
	return 0;
}
