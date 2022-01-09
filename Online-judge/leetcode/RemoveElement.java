package Letcode;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/remove-element
 */
public class RemoveElement {
    public int removeElement(int[] nums, int val) {
        int newLength = -1;
        for (int index = 0; index < nums.length; index++) {
            if (nums[index] != val) {
                nums[++newLength] = nums[index];
            }
        }
        return newLength + 1;
    }
    public static void main(String[] args) {
        RemoveElement r = new RemoveElement();
        int []element = {0,1,2,2,3,0,4,2};
        int re = r.removeElement(element, 2);
        System.out.println(re);
    }
}
