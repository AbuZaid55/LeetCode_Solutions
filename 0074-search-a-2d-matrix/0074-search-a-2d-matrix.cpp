class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int columnSize = matrix[0].size();
        int rowSize = matrix.size();
        
        int top = 0;
        int bottom = rowSize - 1;

        while(top < bottom){
            int mid = top + (bottom - top) / 2;
            if(matrix[mid][columnSize - 1] == target){
                return true;
            }else if(target > matrix[mid][columnSize - 1]){
                top = mid + 1;
            }else{
                bottom = mid;
            }
        }

        int left = 0;
        int right = columnSize - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(matrix[top][mid] == target){
                return true;
            }else if(target > matrix[top][mid]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return false;
    }
};