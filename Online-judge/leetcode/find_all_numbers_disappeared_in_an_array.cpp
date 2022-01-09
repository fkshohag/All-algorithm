#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
		int size = nums.size();
		for(int i = 0; i < size; i++) {
			if(nums[abs(nums[i])-1] > 0) {
				nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
			}
		}
		for(int i =0; i < size; i++) {
			if(nums[i] > 0) {
				res.push_back(i+1);
			}
		}
        return res;
    }
};

int main()
{
	vector<int> v;
	v.push_back(4);
	v.push_back(2);
	v.push_back(4);
	sort(v.begin(), v.end());

	Solution s;
	v = s.findDisappearedNumbers(v);

	for (int i = 0; i < v.size(); i++)
	{
		printf("%d ", v[i]);
	}
	
	printf("\n");
}
