class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;

        if (nums.size() < 4) {
            return result;
        }

        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size() - 3; i++) {

            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            }

            for (int j = i + 1; j < nums.size() - 2; j++) {

                if(j > i+1 && nums[j-1] == nums[j]){
                    continue;
                }

                for (int k = j + 1; k < nums.size() - 1; k++) {

                    if(k>j+1 && nums[k-1] == nums[k]){
                        continue;
                    }

                    for (int l = k + 1; l < nums.size(); l++) {

                        if(l > k+1 && nums[l-1] == nums[l]){
                            continue;
                        }

                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                        if (sum == target) {
                            result.push_back({
                                nums[i],
                                nums[j],
                                nums[k],
                                nums[l]
                            });
                        }
                    }
                }
            }
        }

        return result;
    }
};