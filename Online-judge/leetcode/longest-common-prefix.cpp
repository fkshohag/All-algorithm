# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
# include <map>
# include <cstring>

using namespace std;

class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {

		string res;
		if(strs.size() < 1) return res;
        if(strs.size() == 1) return strs[0];
        
        sort(strs.begin(), strs.end(), [](const string& first, const string& second){
			return first.length() < second.length();
		});

		bool flag = false;
		int index = 0;

		for(int i = 0; i < strs[0].length(); i++) {
			for(int j = 1; j < strs.size(); j++) {
				if(strs[j][i] != strs[0][i]) {
					flag = true;
					break;
				}
				if(j == strs.size()-1) index++;
			}
			if(flag) break;
		}

		if(flag && !index) return res;
		return strs[0].substr(0, index);
    }
};

int main()
{
	vector<string> v;
	v.push_back("aca");
	v.push_back("cba");
	Solution s;
	string res = s.longestCommonPrefix(v);
	cout << res;
}
