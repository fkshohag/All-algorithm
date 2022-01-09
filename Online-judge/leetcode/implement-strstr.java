package Letcode;
public class Solution {
    public int strStr(String haystack, String needle) {
        int notFound = -1;
        if (needle.length() > haystack.length()) return notFound;
        if (needle.length() == 0) return 0;
        if (haystack.equals(needle)) return 0;
        for (int index = 0; index <= haystack.length() - needle.length(); index++) {
            String subStr = haystack.substring(index, index + needle.length());
            if (subStr.equals(needle)) return index;
        }
        return  notFound;
    }
    public static void main(String[] args) {
        String haystack = "hello";
        String needle = "ll";
        Solution s = new Solution();
        System.out.println(s.strStr(haystack, needle));
    }
}
