class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;

        for(int num: nums){
            right += num;
            left = max(left,num);
        }

        while(left < right){
            int mid = left + (right - left) / 2;

            int parts = 1;
            int sum = 0;
            for(int num: nums){
                sum += num;
                if(sum > mid){
                    parts ++;
                    sum = num;
                }
            }

            if(parts > k){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        return left;
    }
};