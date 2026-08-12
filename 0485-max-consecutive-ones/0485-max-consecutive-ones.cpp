class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currentCount = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 1){
                if(maxCount < currentCount){
                    maxCount = currentCount;
                }
                currentCount = 0;
            }else{
                currentCount ++;
            }
        }

        return currentCount > maxCount ? currentCount: maxCount;
    }
};