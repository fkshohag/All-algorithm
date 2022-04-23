# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

/*
  ale -> aple
  apple -> aple
*/
	
bool onEditInsert(string s1, string s2) {
	int firstStringIndex = 0, secondStringIndex = 0;
	while(firstStringIndex < s1.size() && secondStringIndex < s2.size()) {
		if (s1[firstStringIndex] != s2[secondStringIndex]) {
			if(firstStringIndex != secondStringIndex) {
				return false;
			}
			secondStringIndex++;
		}
		else {
			firstStringIndex++;
			secondStringIndex++;
		}
	}  
	return true;
}

bool onEditReplace(string s1, string s2) {
	bool foundDiff = false;
	for (int index = 0 ; index < s1.size(); index++) {
		if (s1[index] != s2[index]) {
			if (foundDiff) {
				return false;
			}
			foundDiff = true;
		}
	}
	return true;
}

bool onEditAway(string s1, string s2) {
	if (s1.size() == s2.size()) {
		return onEditReplace(s1, s2);
	}
	else if (s1.size() + 1 == s2.size()) {
		return onEditInsert(s1, s2);
	}
	else if (s1.size() - 1 == s2.size()) {
		return onEditInsert(s1, s2);
	}
	return false;
}



int main() {
	freopen("in.txt", "r", stdin);
	string s1, s2;
	cin >>s1 >>s2;
	bool result = onEditAway(s1, s2);
	printf("%d\n", result);
	return 0;
}