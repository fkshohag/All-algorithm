# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

char * replaceSpaces(char str[], unsigned long len) {

	int spaceCount = 0, index = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') {
			spaceCount++;
		}
	}	

	index = len + (spaceCount * 2);
	if (len < strlen(str)) {
		str[len] = '\0';
	}

	for (int i = len - 1; i >= 0; i--) {
		if (str[i] == ' ') {
			str[index - 1] = '0';
			str[index - 2] = '2';
			str[index - 3] = '%';
			index = index - 3;
		}
		 else {
		 	str[index - 1] = str[i];
		 	index--;
		 }
	}
	return str;
	
}

int main() {
	freopen("in.txt", "r", stdin);

	char str[100];
	cin.get(str, 100);
	unsigned long len = strlen(str);
	char *result = replaceSpaces(str, len);
	printf("%s\n", str);

	/*
	input: I love you bangladesh
	output: I%20love%20you%20bangladesh
	*/
}