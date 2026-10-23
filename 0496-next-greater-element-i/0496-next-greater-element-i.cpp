class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int i = 0; i<nums2.size(); i++){
            mp[nums2[i]] = i;
        }

        vector<int> result;

        for(int num: nums1){
            int index = mp[num] + 1; 
            while(index < nums2.size()){
                if(nums2[index] > num){
                    result.push_back(nums2[index]);
                    break;
                }
                index++;
            }
            if(index == nums2.size()){
                result.push_back(-1);
            }
        }

        return result;
    }
};