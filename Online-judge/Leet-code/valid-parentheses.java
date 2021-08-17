package Letcode;

import java.util.Stack;

public class Solution {
    public boolean isValid(String s) {
        char [] openBracket = {'(', '{', '['};
        char [] closingBracket = {')', '}', ']'};

        Stack<Character> stack = new Stack<>();
        for (int index = 0; index < s.length(); index++) {
            char c = s.charAt(index);
            if (c == openBracket[0] || c == openBracket[1] || c == openBracket[2]) {
                stack.push(c);
            } else {
                if (stack.isEmpty()) return false;
                if ((stack.peek() == openBracket[0] && c == closingBracket[0]) || (stack.peek() == openBracket[1] &&
                        c == closingBracket[1]) || (stack.peek() == openBracket[2] && c == closingBracket[2])
                ) {
                    stack.pop();
                } else return false;
            }
        }
        return  stack.empty();
    }
    public static void main(String[] args) {
        String str = "({})";
        Solution s = new Solution();
        System.out.println(s.isValid(str));
    }
}
