# include <iostream>
# include <cstring>
# include <cstring>
# include <vector>
# include <map> 
# include <queue>

using namespace std;

int main() {

	freopen("in.txt", "r", stdin);

	int m, n;
	scanf("%d %d", &m, &n);

	map<string, int> magazine;

	for (int index = 0; index < m; index++) {
		string word;
		cin >> word;
		if (magazine.find(word) == magazine.end()) {
			magazine[word] = 1;
		} else {
			magazine[word]++;
		}
	}

	bool ans = true;

	for (int index = 0; index < n; index++) {
		string word;
		cin >> word;
		if (magazine.find(word) == magazine.end() || magazine[word] == 0) {
			ans = false;
			break;
		} else {
			magazine[word]--;
		}
	}

	if (ans) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;

}