class Solution {

    public void solve(
        int index,
        String digits,
        StringBuilder current,
        List<String> result,
        String[] mp
    ) {

        // Base case
        if (index == digits.length()) {
            result.add(current.toString());
            return;
        }

        // Get letters for current digit
        String letters = mp[digits.charAt(index) - '0'];

        // Try every letter
        for (char ch : letters.toCharArray()) {

            // Choose
            current.append(ch);

            // Explore
            solve(index + 1, digits, current, result, mp);

            // Undo
            current.deleteCharAt(current.length() - 1);
        }
    }

    public List<String> letterCombinations(String digits) {

        if (digits.length() == 0) {
            return new ArrayList<>();
        }

        String[] mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        List<String> result = new ArrayList<>();
        StringBuilder current = new StringBuilder();

        solve(0, digits, current, result, mp);

        return result;
    }
}