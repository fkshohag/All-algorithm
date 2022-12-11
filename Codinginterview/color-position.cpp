# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <map>
# include <stack>
# include <queue>

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

void show(vector<string>v) {
	for (int index = 0; index < v.size(); index++) {
		cout << v[index] << " ";
	}
}

void remap(vector<string>v) {
	map<int, string> mp;
	for (int i = 0; i < v.size(); i++) {
		int key = v[i][v[i].size() - 1] - '0';
		mp[key] = v[i].substr(0, v[i].size());
	}
	vector<string> ans;
	map<int, string>::iterator it;
	for (it = mp.begin(); it != mp.end(); it++) {
		ans.push_back(it->second);
	}
	string s = join(ans);
	cout << s;
}


int main() {
	string str = "red2 black1 green4";
	string delimiter = " ";
	vector<string>v = split(str, delimiter);
	remap(v);

	return 0;
}