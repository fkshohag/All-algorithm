# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>

using namespace std;

vector<string> split(string s, string delimiter) {
	size_t pos_start = 0 , pos_end, delimiter_len = delimiter.size();

	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delimiter_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}

string join(vector<string>v) {
	string s = "";

	for (int index = 0; index < v.size(); index++) {
		s += " " + v[index];
	}
	return s.substr(1, s.size());
}



int main() {
	string str = "red2 black1 green4";
	string delimiter = " ";
	vector<string>v = split(str, delimiter);

	string s = join(v);
	cout << s;

	return 0;
}