# include <iostream>
# include <cstdio>
using namespace std;

class NumArray {
private: 
    int size;
    vector<int>tree;
    
    void build(vector<int> &nums, int left, int right, int index) {
        if (left == right) {
            tree[index] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        build(nums, left, mid, 2 * index + 1);
        build(nums, mid + 1, right, 2 * index + 2);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
    
    void updateTree(int left, int right, int index, int i, int x) {
        if (left == right) {
            tree[index] = x;
            return;
        }
        int mid = left + (right - left) / 2;
        if (i <= mid) {
            updateTree(left, mid, 2 * index + 1, i, x);
        } else {
            updateTree(mid + 1, right, 2 * index + 2, i, x);
        }
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
    
    int query(int left, int right, int index, int &start, int &end) {
        if (left >= start && right <= end) {
            return tree[index];
        }
        if (left > end || right < start) return 0;
        int mid = left + (right - left) / 2;
        return query(left, mid, 2 * index + 1, start, end) + query(mid + 1, right, 2 * index + 2, start, end);
    }
    
public:
    NumArray(vector<int>& nums) {
        size = nums.size();
        tree = vector<int>(4 * size);
        build(nums, 0, size - 1, 0);
    }
    
    void update(int index, int val) {
        updateTree(0, size -1, 0, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, size - 1, 0, left, right);
    }
};

int main() {

 NumArray* obj = new NumArray(nums);
 obj->update(index,val);
 int param_2 = obj->sumRange(left,right);
 return 0;
}
