class Solution {
public:
    void solve(int start, int k, int remaining, vector<int>& temp, vector<vector<int>>& result){
        if(temp.size() == k){
            if(remaining == 0){
                result.push_back(temp);
            }
            return;
        }

        for(int i = start; i<=9; i++){
            if(i > remaining){
                break;
            }

            temp.push_back(i);
            solve(i + 1, k, remaining - i, temp, result);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;

        solve(1, k, n, temp, result);

        return result;
    }
};