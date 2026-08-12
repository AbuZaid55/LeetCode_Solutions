class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nonZero;
        vector<int> zero;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                zero.push_back(nums[i]);
            }else{
                nonZero.push_back(nums[i]);
            }
        }

        int current = 0;
        for(int i=0; i<nonZero.size(); i++){
            nums[current++] = nonZero[i];
        }
        for(int i=0; i<zero.size(); i++){
            nums[current++] = zero[i];
        }
    }
};