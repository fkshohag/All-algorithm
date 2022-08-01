# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/range-sum-query-immutable/
 */


class NumArray {
private:
    int size;
    vector<int> segmentTree;
    void buildSegmentTree(vector<int>& nums, int left, int right, int index) {
        if (left == right) {
            segmentTree[index] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildSegmentTree(nums, left, mid, 2 * index + 1);
        buildSegmentTree(nums, mid + 1, right, 2 * index + 2);
        segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
    }
    
    int query(int left, int right, int index, int start, int end) {
        if (left >= start && right <= end) {
            return segmentTree[index];
        }
        if (left > end || right < start) return 0;
        int mid = left + (right - left) / 2;
        return query(left, mid, 2 * index + 1, start, end) + query(mid + 1, right, 2 * index + 2, start, end);
    }
    
public:
    NumArray(vector<int>& nums) {
        size = nums.size();
        segmentTree = vector<int>(4 * size);
        buildSegmentTree(nums, 0, size - 1, 0);
    }
    
    int sumRange(int left, int right) {
        return query(0, size - 1, 0, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */