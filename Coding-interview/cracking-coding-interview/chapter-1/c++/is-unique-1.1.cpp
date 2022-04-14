# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

bool isUnique(string str) {
	if (str.size() > 128) return false;
	bool flag [128 + 1];

	for(int index = 0; index <= 128; index++) {
		flag[index] = false;
	}

	int key;
	for(int index = 0; index < str.size(); index++) {
		key = (int) str[index];
		if(flag[key]) {
			return false;
		}
		flag[key] = true;
	}
	return true;
}

int main() {
	// freopen("in.txt", "r", stdin);
	string str;
	cin>>str;
	bool result = isUnique(str);
	if(result) {
		printf("Unique\n");
	} else {
		printf("Not Unique\n");
	}
	return 0;

	/*input 
	 hel -> true
	 hello -> false
	*/
}