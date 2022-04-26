# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

string stringCompression(string str) {
	int len = str.size();
	int characterRepeatCounter = 0;
	string compressString = "";

	for (int index = 0; index < len; index++) {
		characterRepeatCounter++;
		if ((index + 1) >= len || str[index] != str[index + 1]) {
			compressString += str[index] + to_string(characterRepeatCounter);
			characterRepeatCounter = 0;
		}
	}
	return compressString;
}

int main() {
	// freopen("in.txt", "r", stdin);
	string str;
	cin >> str; 
	string result = stringCompression(str);
	cout << result << endl;
	return 0;
}