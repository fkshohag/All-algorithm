# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/jump-game/description/
 *
*/

/**
 * @brief 
 * Time complexity O(n^2)
 * Space complexity o(2n) = O(n)
 */

const int UNKNOWN = -1, GOOD = 1, BAD = 2;

class Solution {
private:
    vector<int> dp;
    int N;
    bool solve(int position, vector<int>& nums) {
        if (position == N - 1) return true;
        if (dp[position] != UNKNOWN) {
            return dp[position] == GOOD ? true : false;
        }

        int maximumJumAllow = min(position + nums[position], N - 1);
        for (int nextPosition = position + 1; nextPosition <= maximumJumAllow; nextPosition++) {
            if (solve(nextPosition, nums)) {
                dp[position] = GOOD;
                return true;
            }
        }
        dp[position] = BAD;
        return false;
    }

public:
    bool canJump(vector<int>& nums) {
        N = nums.size();
        dp = vector<int> (N, UNKNOWN);
        return solve(0, nums);
    }
};

/**
 * @brief 
 * Time complexity O(n)
 * Space complexity O(1)
 */

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int maxJumpIndex = 0;
            int N = nums.size();

            for (int position = 0; position < N; position++) {
                maxJumpIndex = max(maxJumpIndex, position + nums[position]);
                if (maxJumpIndex < position + 1) break;
            }
            return maxJumpIndex >= N-1;
        }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> maxJump(nums.size(),0);
        maxJump[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(maxJump[i-1] < i) return false;
            maxJump[i] = max(maxJump[i-1],nums[i]+i);
        }
        return true;
    }
};