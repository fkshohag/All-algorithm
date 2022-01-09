package Letcode;
/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/maximum-subarray/
 */
public class MxSubArray {
    public int maxSubArray(int[] nums) {

        int currentMaxSum = 0, maxSum = Integer.MIN_VALUE;
        for (int number:nums) {
            currentMaxSum = Math.max(number, currentMaxSum + number);
            maxSum = Math.max(maxSum, currentMaxSum);
        }
        
        return  maxSum;
    }
    public static void main(String[] args) {
        int []element = {-2,1,-3,4,-1,2,1,-5,4};
        MxSubArray mx = new MxSubArray();
        int ans = mx.maxSubArray(element);
        System.out.println(ans);
    }
}
