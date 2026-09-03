class Solution {
public:
    void getCombination(vector<int>& current, int sum, int start, vector<int>& candidates, int target, vector<vector<int>>& result){
        if(sum == target){
            result.push_back(current);
        }

        if(sum > target){
            return;
        }

        for(int i = start; i<candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i - 1]){
                continue;
            }
            current.push_back(candidates[i]);
            getCombination(current, sum + candidates[i], i + 1, candidates, target, result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        
        vector<int> current;
        vector<vector<int>> result;
        getCombination(current, 0, 0, candidates, target, result);
        return result;
    }
};