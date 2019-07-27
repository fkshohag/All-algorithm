# include <cstdio>
# include <iostream>
# include <cstring>
# include <vector>
using namespace std;
# define pb push_back
# define SIZE 10000
bool isPrime[SIZE+1];
vector <int> prime;
vector <int> factors;  
int number_of_divisor = 0;

void sieve(int N) {
	for(int i = 4; i <= N; i += 2)
		isPrime[i] = false;
	for(int i = 3 ; i*i <= N; i += 2) {
		if(isPrime[i]) { // isPrime[i] is isPrime that's way not false yet
			for(int j = i*i; j <= N; j +=i)
				isPrime[j] = false;
		}
	}
	isPrime[1] = false;
}

void primeFactorization(int N) {
	int PF_idx = 0, PF = prime[PF_idx], ans = 1; //we store divisor 
	while(PF * PF <= N) {
		int power = 0;
		while(N % PF == 0) {
			N /= PF;
			factors.pb(PF);
			power++;
		}
		ans *= (power + 1); // N has (i+1)*(j+1)*.......*(k+1) divisor
		PF = prime[++PF_idx];
	}
	if(N != 1){
		ans *= 2; // last factor has pow = 1, we add 1 to it
		factors.pb(N);
	}
	number_of_divisor = ans;
}

int main() {
	memset(isPrime, true, sizeof(isPrime));
	int N = 32;
	sieve(N);
	for(int i = 2; i<= SIZE; i++)
		if(isPrime[i])
			prime.pb(i);
	primeFactorization(N);
	for(int i =0; i < factors.size(); i++)
		printf("%d ", factors[i]);
	printf("\n%d\n", number_of_divisor);
  return 0;
}
