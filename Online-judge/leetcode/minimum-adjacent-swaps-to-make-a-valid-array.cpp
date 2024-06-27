class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    int minimumSwaps(vector<int>& nums) {
        int minEl = INT_MAX, maxEl = INT_MIN;
        int minIdx = 0, maxIdx = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] < minEl) {
                minEl = nums[i];
                minIdx = i;
            }
            if (nums[i] >= maxEl) {
                maxEl = nums[i];
                maxIdx = i;
            }
        }
        // subtract one common swap of min & max when minNumIndex > maxNumIndex
        return ((n - 1 - maxIdx) + minIdx) - (minIdx > maxIdx ? 1: 0);
    }
};