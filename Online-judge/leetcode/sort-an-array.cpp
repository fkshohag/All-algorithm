# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/sort-an-array/description/
 * Time complexity O(NlogN) sort taks O(NlogN)
 * Space complexity O(1)
*/

class Solution {
private:

	void swap(int *a, int *b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	int partition(vector<int> &nums, int low, int high) {
		int counter = low-1;
		int pivot = nums[high];
		for(int i = low; i < high; i++) {
			if (nums[i] <= pivot) {
				counter++;
				swap(&nums[counter], &nums[i]);
			}
		}
		swap(&nums[counter+1], &nums[high]);
		return counter+1;
	}

	void QuickSort(vector<int>& nums, int low, int high) {
		if(low < high) {
			int pi = partition(nums, low, high);
			QuickSort(nums, low, pi-1);
			QuickSort(nums, pi+1, high);
		}
	}

public:
    vector<int> sortArray(vector<int>& nums) {
    	if(nums.size() < 2) return nums;
    	QuickSort(nums, 0, nums.size()-1);
    	return nums;
    }
};