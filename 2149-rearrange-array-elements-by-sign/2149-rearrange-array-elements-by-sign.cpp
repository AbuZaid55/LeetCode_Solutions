class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positiveNums;
        vector<int> negativeNums;
        vector<int> resultNums;

        for(int i =0; i<nums.size(); i++){
            if(nums[i] >= 0) {
                positiveNums.push_back(nums[i]);
            }else{
                negativeNums.push_back(nums[i]);
            }
        }

        for(int i = 0; i<positiveNums.size(); i++){
            resultNums.push_back(positiveNums[i]);
            resultNums.push_back(negativeNums[i]);
        }

        return resultNums;
    }
};