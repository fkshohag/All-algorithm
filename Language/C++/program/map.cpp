# include <iostream>
# include <cstdio>
# include <map>
# include <iterator>
using namespace std;

map<string, string> m;

string get(string key) {
	map<string, string>::iterator itr;
	for(itr = m.begin(); itr != m.end(); itr++) {
		if(itr->first == key) {
			return itr->second;
		}
	}
	string empty = "";
	return empty;
}

int main() {
	map<string, string>::iterator itr;

	m["name"] = "shohag";
	m["dept"] = "CSE";
	m.insert({"address", "Dhaka, Mirpur-10"});

	cout<<get("name");
}

