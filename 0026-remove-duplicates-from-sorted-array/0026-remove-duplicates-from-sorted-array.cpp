class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, bool> mp;

        for(int i = 0; i<nums.size(); i++){
            if(!mp[nums[i]]){
                result.push_back(nums[i]);
                mp[nums[i]] = true;
            }
        }

        for(int i = 0; i<result.size(); i++){
            nums[i] = result[i];
        }

        return result.size();
    }
};