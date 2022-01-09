# include <iostream>
# include <cstdio>
using namespace std;
#define mx 100001

int arr[mx], tree[mx*4];

void prepareTree(int node, int l, int r) {
	if(l == r) {
		tree[node] = arr[l];
		return;
	}
	int left = (node * 2);
	int right = (node * 2 + 1);
	int mid = (int) (l + r) / 2;
	prepareTree(left, l, mid);
	prepareTree(right, mid +1 , r);
	tree[node] = tree[left] + tree[right];
}

int query(int node, int l, int r, int i, int j) {
	if(i > r || j < l) return 0; // outside the range
	else if(i <= l && j>=r) return tree[node]; // inside the range
	int left = (node * 2);
	int right = (node*2 +1);
	int mid = (l + r) / 2;
	int p1 = query(left, l, mid, i, j);
	int p2 = query(right, mid+1, r, i, j);
	return p1 + p2;

}

void update(int node , int l, int r, int i, int j, int val) {
	if(i > r || j < l) return;

	else if (i <= l && j >= r) {
		tree[node] = val;
		return;
	}

	int left = (node * 2);
	int right = (node * 2 + 1);
	int mid = (l + r) / 2;

	update(left, l, mid, i, j, val);
	update(right, mid+1, r, i, j, val);
	tree[node] = tree[left] + tree[right];
}

int main() {
	int n = 8;
	for(int i = 1; i <= n; i++)
		arr[i] = i;

	prepareTree(1, 1, n);

	for(int i = 1; i <= 15; i++) // total node = 15 after segmentation
		printf("%d ", tree[i]);
	int q = query(1, 1, n, 2, 4);

	printf("\nresult = %d", q);
	update(1, 1, n, 3, 3,55);
	printf("\n");
	
	for (int i =1; i <= 15; i++)
		printf("%d ", tree[i]);

	return 0;
}
