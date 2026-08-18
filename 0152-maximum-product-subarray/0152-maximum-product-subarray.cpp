class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int currentMax = nums[0];
        int currentMin = nums[0];
        int answer = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int num = nums[i];

            // If num is negative, max and min will swap
            if (num < 0) {
                swap(currentMax, currentMin);
            }

            currentMax = max(num, currentMax * num);
            currentMin = min(num, currentMin * num);

            answer = max(answer, currentMax);
        }

        return answer;
    }
};