package Letcode;
/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/search-insert-position/
 */
public class InsertPosition {
    public int searchInsert(int[] nums, int target) {
        int len = nums.length - 1;
        if (target > nums[len]) return len + 1;
        int left = 0, right = len-1;
        while (left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] > target) {
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return left;
    }
    public static void main(String[] args) {
        int []element = {1,3,5,6};
        InsertPosition insert = new InsertPosition();
        int ans = insert.searchInsert(element, 7);
        System.out.println(ans);
    }
}
