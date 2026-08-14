class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> resultNums(nums.size(), 0);
        int postivePosition = 0;
        int negativePosition = 1;

        for(int i =0; i<nums.size(); i++){
            if(nums[i] >= 0) {
                resultNums[postivePosition] = nums[i];
                postivePosition += 2;
            }else{
                resultNums[negativePosition] = nums[i];
                negativePosition += 2;
            }
        }

        return resultNums;
    }
};