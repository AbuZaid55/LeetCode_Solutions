class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        int minIndex = left + (right - left) / 2;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[minIndex]){
                minIndex = mid;
            }
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return nums[minIndex];
    }
};