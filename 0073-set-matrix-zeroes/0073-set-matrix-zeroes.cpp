class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> rowToBeZero(matrix.size(), false);
        vector<bool> columnToBeZero(matrix[0].size(), false);

        for(int i =0; i<matrix.size(); i++){
            for(int j = 0; j< matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rowToBeZero[i] = true;
                    columnToBeZero[j] = true;
                }
            }
        }

        for(int i =0; i<matrix.size(); i++){
            for(int j = 0; j< matrix[0].size(); j++){
                if(rowToBeZero[i] == true || columnToBeZero[j] == true){
                    matrix[i][j] = 0;
                }
            }
        }

    }
};