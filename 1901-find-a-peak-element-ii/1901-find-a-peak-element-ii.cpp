class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int left = 0;
        int right = cols - 1;

        while (left <= right) {
            int midCol = left + (right - left) / 2;

            int maxRow = 0;

            for (int row = 1; row < rows; row++) {
                if (mat[row][midCol] > mat[maxRow][midCol]) {
                    maxRow = row;
                }
            }

            int current = mat[maxRow][midCol];
            int leftValue = (midCol > 0) ? mat[maxRow][midCol - 1] : -1;
            int rightValue = (midCol < cols - 1) ? mat[maxRow][midCol + 1] : -1;

            if (current > leftValue && current > rightValue) {
                return {maxRow, midCol};
            }

            if (leftValue > current) {
                right = midCol - 1;
            } else {
                left = midCol + 1;
            }
        }

        return {-1, -1};
    }
};