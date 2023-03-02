# include <bits/stdc++.h>


using namespace std;

class Solution {
protected:
	int x;

public:
	Solution(int xx) {
		x = xx;
	}

	void showX() {
		printf("Hello you ???");
	}
};

class MiddleMan {

};

class Problem: public Solution, MiddleMan {
public:
	Problem(int jjj): Solution(jjj) {
		x = jjj;
	}
};


int main() {
	Problem p(3);
	p.showX();
	return 0;
}