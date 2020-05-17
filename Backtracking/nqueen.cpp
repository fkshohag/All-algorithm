# include <iostream>
# include <cstdio>
# define breakLine cout << "\n---------------------------------\n"; 
# define N 100

using namespace std;

class Chess{
public:
	int queens[N], no;

	Chess() {
		no = 0;
	}

	bool isPlace(int k, int i) {
		for(int j = 1; j <= k-1; j++)
			if(queens[j] == i || (abs(queens[j] -i) == abs(j - k))) return false;
		return true;
	}

	void nQueen(int k, int n) {
		for(int i = 1; i <= n; i++){
			if(isPlace(k, i)) {
				queens[k] = i;
				if(k == n) display(n);
				else {
					nQueen(k + 1, n);
				}
			}
		}
	}

	void display(int n) {
		breakLine
		cout << "Arrangement No. " << ++no; 
		breakLine
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(queens[i] != j) printf("\t__");
			    else printf("\tQ");
			} 
			printf("\n");
		}
		breakLine
	}
};


int main() {
	Chess s;
	s.nQueen(1,4);
}
