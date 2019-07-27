# include <cstdio>
# include <iostream>
# include <cstring>
using namespace std;
# define N 10000
bool prime[N+1];
 
void sieve() {
	for(int i = 4; i <= N; i += 2)
		prime[i] = false;
	for(int i = 3 ; i*i <= N; i += 2) {
		if(prime[i]) { // prime[i] is prime that's way not false yet
			for(int j = i*i; j <= N; j +=i)
				prime[j] = false;
		}
	}
	prime[1] = false;
}

int main() {
	memset(prime, true, sizeof(prime));
	sieve();
	for(int i = 2; i<= N; i++)
		if(prime[i])
			printf("%d ", i);
  return 0;
}
