class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int currentCount = 0;

        for(int i = 0; i<nums.size() -1; i++){
            if(nums[i] != nums[i+1] && currentCount==0){
                return nums[i];
            }
            else if(nums[i] != nums[i+1] && currentCount > 0){
                currentCount = 0;
            }
            else{
                currentCount++;
            }
        }

        return nums.back();
    }
};