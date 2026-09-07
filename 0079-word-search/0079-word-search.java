class Solution {

    public boolean searchWord(
        int row,
        int col,
        int pos,
        boolean[][] visited,
        char[][] board,
        String word
    ) {
        // We have matched the entire word
        if (pos == word.length()) {
            return true;
        }

        // Out of bounds
        if (row < 0 || row >= board.length ||
            col < 0 || col >= board[0].length) {
            return false;
        }

        // Already used this cell
        if (visited[row][col]) {
            return false;
        }

        // Current character doesn't match
        if (board[row][col] != word.charAt(pos)) {
            return false;
        }

        // Mark current cell as used
        visited[row][col] = true;

        // Search in 4 directions
        boolean found =
            searchWord(row + 1, col, pos + 1, visited, board, word) ||
            searchWord(row - 1, col, pos + 1, visited, board, word) ||
            searchWord(row, col + 1, pos + 1, visited, board, word) ||
            searchWord(row, col - 1, pos + 1, visited, board, word);

        // Backtrack
        visited[row][col] = false;

        return found;
    }

    public boolean exist(char[][] board, String word) {

        boolean[][] visited =
            new boolean[board.length][board[0].length];

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {

                if (board[i][j] == word.charAt(0)) {

                    if (searchWord(i, j, 0, visited, board, word)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
}