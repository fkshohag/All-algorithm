# include <cstdio>
# include <cmath>
# define sq(x) ((x)*(x))
struct Point
{
	int x,y;
};
int main()
{
	Point A,B;
	A.x=-2;B.x=1;
	A.y=3;B.y=-1;
	int result=sqrt(sq(A.x-B.x)+sq(A.y-B.y));
	printf("%d\n",result);
	return 0;
}
