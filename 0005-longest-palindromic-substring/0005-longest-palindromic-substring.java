class Solution {
    public String longestPalindrome(String s) {

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < s.length(); i++) {

            // Odd length palindrome: "aba"
            int left = i;
            int right = i;

            while (left >= 0 && right < s.length()
                    && s.charAt(left) == s.charAt(right)) {

                int length = right - left + 1;

                if (length > maxLength) {
                    start = left;
                    maxLength = length;
                }

                left--;
                right++;
            }

            // Even length palindrome: "abba"
            left = i;
            right = i + 1;

            while (left >= 0 && right < s.length()
                    && s.charAt(left) == s.charAt(right)) {

                int length = right - left + 1;

                if (length > maxLength) {
                    start = left;
                    maxLength = length;
                }

                left--;
                right++;
            }
        }

        return s.substring(start, start + maxLength);
    }
}