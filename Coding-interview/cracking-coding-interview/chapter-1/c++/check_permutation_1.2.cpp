# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

bool isPermutation(string s, string t) {
	if (s.size() != t.size()) {
		return false;
	}

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	if (s == t) {
		return true;
	}

	return false;
}

int main() {
	// freopen("in.txt", "r", stdin);

	string s, t;
	cin >> s >> t;
	bool result = isPermutation(s, t);

	if (result) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}