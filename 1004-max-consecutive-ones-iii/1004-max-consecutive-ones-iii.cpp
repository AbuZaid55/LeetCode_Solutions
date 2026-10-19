class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0; 
        int right = 0;

        int tempK = k;

        int maxCount = 0;

        while(left < nums.size() && right< nums.size()){
            if((nums[right] == 0 && tempK !=0) || nums[right] != 0){
                if(nums[right] == 0){
                    tempK--;
                }
                right++;
                maxCount = max(maxCount, right - left);
            }else{
                left++;
                right = left;
                tempK = k;
            }
        }

        return maxCount;
    }
};