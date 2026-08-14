class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        int totalElement = rowSize * colSize;

        int current = 1;

        int row = 0;
        int column = 0;

        vector<int> result;

        int min = INT_MIN;
        string direction = "col+";

        result.push_back(matrix[0][0]);
        matrix[0][0] = min;
        current++;

        while(current <= totalElement){
            if(direction == "col+" && (column >= colSize - 1 || matrix[row][column + 1] == min)){
                direction = "row+";
            }else if(direction == "row+" && (row >= rowSize -1 || matrix[row + 1][column] == min)){
                direction = "col-";
            }else if(direction == "col-" && (column <= 0 || matrix[row][column -1] == min)){
                direction = "row-";
            }else if(direction == "row-" && (row <= 0 || matrix[row - 1][column] == min)){
                direction = "col+";
            }
            
            if(direction == "col+"){
                column++;
            }else if(direction == "row+"){
                row++;
            }else if(direction == "col-"){
                column--;
            }else{
                row--;
            }
            result.push_back(matrix[row][column]);
            matrix[row][column] = min;
            current++;
        }

        return result;
    }
};