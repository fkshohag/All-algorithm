package Letcode;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/missing-number
 */

public class MissingNumber {
    public int missingNumber(int[] nums) {
        int mxLength = nums.length + 1;
        
        int [] visited = new int [mxLength];
        for(int index = 0; index < nums.length; index++) {
            visited[nums[index]] = nums[index];
        }

        int res = 0;
        for (int index = 0; index < visited.length; index++) {
            if (visited[index] != index) {
                res = index;
                break;
            }
        }
        return res;
    }
    public static void main(String[] args) {
        int [] nums = {1};
        MissingNumber number = new MissingNumber();
        System.out.println(number.missingNumber(nums));
    }
}
