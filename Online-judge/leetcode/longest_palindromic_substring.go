func longestPalindrome(s string) string {
	var length int = len(s)

	if length < 0 {
		return s
	}
	
	var longestPalindrome string = ""
	var longestPalindromeLenght int = 0

	for index := 0; index < length; index++ {

		left, right := expandString(s, length, index, index)
		_left, _right := expandString(s, length, index, index+1)
		mx := len(s[left:right])
		_mx := len(s[_left:_right])

		if mx > _mx && mx > longestPalindromeLenght {
			longestPalindromeLenght = mx
			longestPalindrome = s[left:right]
		} else {
			if _mx > longestPalindromeLenght {
				longestPalindromeLenght = _mx
				longestPalindrome = s[_left:_right]
			}
		}
	}
	return longestPalindrome

}

func expandString(word string, length int, left int, right int) (int, int) {
	for left >= 0 && right < length && word[left] == word[right] {
		left--
		right++
	}
	return left + 1, right
}

