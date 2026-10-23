class Solution {
private:
    int atMostSubarray(vector<int>&nums, int k){
        int left = 0;
        int count = 0;
        int result = 0;
        unordered_map<int, int> mp;
        for(int right = 0; right<nums.size(); right++){
            if(mp[nums[right]] == 0){
                count++;
            }
            mp[nums[right]]++;

            while(count > k){
                mp[nums[left]] --;
                if(mp[nums[left]] == 0){
                    count--;
                }
                left++;
            }
            
            result += right - left + 1;
        }
        return result;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostSubarray(nums, k) - atMostSubarray(nums, k -1);
    }
};