class Solution {
    public int lengthOfLastWord(String s) {
        int lenCounter = 0;
        int olderStringLen = 0;
        char firstLatter = ' ';
        for (int index = 0; index < s.length(); index++) {
            if (s.charAt(index) != ' ' && firstLatter == ' '){
                lenCounter++;
                firstLatter = s.charAt(index);
            }
            else if (s.charAt(index) != ' ') {
                lenCounter++;
            }
            else {
                firstLatter = ' ';
                olderStringLen = lenCounter > 0 ? lenCounter : olderStringLen;
                lenCounter = 0;
            }
        }
        return lenCounter != 0 ? lenCounter: olderStringLen;
    }
}
