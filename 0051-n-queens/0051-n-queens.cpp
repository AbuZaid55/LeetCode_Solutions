class Solution {
public:

    bool isSafe(int row, int col, int n, vector<string>& board) {

        // Check same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        int i = row - 1;
        int j = col - 1;

        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }

            i--;
            j--;
        }

        // Check upper-right diagonal
        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') {
                return false;
            }

            i--;
            j++;
        }

        return true;
    }

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& result) {

        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (!isSafe(row, col, n, board)) {
                continue;
            }

            board[row][col] = 'Q';

            solve(row + 1, n, board, result);

            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> result;

        vector<string> board(n,string(n, '.'));

        solve(0, n, board, result);

        return result;
    }
};