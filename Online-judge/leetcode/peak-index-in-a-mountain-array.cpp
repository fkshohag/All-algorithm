# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/
 * Time complexity  O(log(n))
 * Space complexity O(1)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1, mid;

        while (left < right) {
            mid = (left + right) / 2;
            if (arr[mid] > arr[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int peakIndexInMountainArrayAlternative(vector<int>& arr) {
        int index = 0;
        while (arr[index] < arr[index + 1]) {
            index++;
        }
        return index;
    }
};
