class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int current = 0;
        int size = nums.size();
        for(int i =0; i< size; i++){
            if(nums[i] != 0){
                nums[current++] = nums[i];
            }
        }

        while(current<size){
            nums[current++] = 0;
        }
    }
};