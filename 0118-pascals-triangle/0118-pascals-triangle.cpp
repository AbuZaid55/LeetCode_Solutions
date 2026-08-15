class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows >= 1){
            result.push_back({1});
        }
        if(numRows >= 2) {
            result.push_back({1, 1});
        }
        for(int i = 2; i<numRows; ++i){
            vector<int> lastRow = result[i-1];
            int temp = lastRow[0];
            for(int j = 1; j<lastRow.size(); ++j){
                int sum = temp + lastRow[j];
                temp = lastRow[j];
                lastRow[j] = sum;
            }
            lastRow.push_back(1);
            result.push_back(lastRow);
        }
        return result;
    }
};