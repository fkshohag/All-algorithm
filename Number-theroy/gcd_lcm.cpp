# include <stdio.h>
int gcd(int a, int b) {
	int temp;
	while(a % b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return b;
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
int main() {
	//freopen("in.txt", "r", stdin);
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", gcd(gcd(a, b), c));
	printf("%d\n", lcm(lcm(a,b), c));
	return 0;
}
