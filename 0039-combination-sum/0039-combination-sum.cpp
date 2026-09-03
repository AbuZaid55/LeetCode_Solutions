class Solution {
public:
    void combination (vector<int>& current, int sum, vector<vector<int>>& ans, vector<int>& candidates, int target, int start){
                   
        if(sum == target){
            ans.push_back(current);
            return;
        }
        
        if(sum > target){
            return;
        }

        for(int i = start; i<candidates.size(); i++){
            current.push_back(candidates[i]);
            combination(current,sum+candidates[i], ans, candidates, target, i);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        combination(current,0, ans, candidates, target , 0);
        return ans;
    }
};