class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr(128,-1);
        int left = 0;
        int right = 0;
        int maxLength = 0;
        while(right < s.length()){
            if(arr[s[right]] >= left){
                left = arr[s[right]] + 1;
            }
            arr[s[right]] = right;
            maxLength = max(maxLength, (right - left + 1));
            right++;
        }
        return maxLength;
    }
};