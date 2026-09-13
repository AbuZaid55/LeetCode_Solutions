class Solution {
public:
    void makeSubset(vector<int>& current, int start, vector<int>& nums, vector<vector<int>>& result){
        result.push_back(current);

        for(int i = start; i<nums.size(); i++){
            current.push_back(nums[i]);
            makeSubset(current, i + 1, nums, result );
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        makeSubset(current, 0, nums, result);
        return result;
    }
};