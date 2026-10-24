class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int ptr = i + 1;
            while(ptr < n + i){
                if(nums[ptr % n] > nums[i]){
                    result.push_back(nums[ptr % n]);
                    break;
                }
                ptr++;
            }

            if(ptr % n == i){
                result.push_back(-1);
            }
        }
        return result;
    }
};