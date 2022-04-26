
/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://www.hackerrank.com/challenges/sparse-arrays/problem
 */

# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
	int repeatedStringCouter;
	vector<int> queryResult;

	for (int qIndex = 0; qIndex < queries.size(); qIndex++) {
		repeatedStringCouter = 0;

		for (int index = 0; index < strings.size(); index++) {
			if (queries[qIndex] == strings[index]) {
				repeatedStringCouter++;
			}
		}
		
		queryResult.push_back(repeatedStringCouter);
	}
	return queryResult;
}

int main() {

}