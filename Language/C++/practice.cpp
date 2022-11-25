# include <bits/stdc++.h>

using namespace std;

int main() {
	int data[] = {2,3,4,5,5};
	int n = sizeof(data) / sizeof(data[0]);
	vector<int> v(data, data+n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int index = 0; index < v.size(); index++) {
		printf("%d ", v[index]);
	}
}