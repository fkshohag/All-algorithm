# include <iostream>
# include <cstdio>
# include <climits>
# include <deque>
# include <vector>
# include <cmath>
# include <sstream>
# include <list>
# include <map>
# include <set>
# include <string>
# include <cstdlib>

using namespace std;

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int isPrime(int n) {
	if (n < 2) return false;
	if (n <= 3) return true;
	if (!(n % 2) || !(n % 3)) return false;

	for (int i = 5; i * i <= n; i+=6) {
		if (!(n%i) || !(n % (i+2))) return false;
	}
	return true;
}


int factor(int n) {
	if (!(n%2)) return 2;
	for (int i = 3; i*i<=n; ++++i) {
		if(!(n%i)) return i;
	}
	return n;
}

void primeFactorization(int n) {
	int r;
	while(n>1) {
		r = factor(n);
		printf("%d ", r);
		n /= r; 
	}
}

bool isLeapYear(int n) {
	if (!(n%100))
		if(!(n%400)) return true;
	    else false;

	if(!(n%4)) true ;
	return false;
}

int main() {
	return 0;
}