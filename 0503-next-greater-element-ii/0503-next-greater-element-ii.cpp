class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result (n,-1);
        stack<int> st;

        for(int i = 0; i<2*n; i++){
            int idx = i % n;
            int num = nums[idx];
            while(!st.empty() && num > nums[st.top()]){
                result[st.top()] = num;
                st.pop();
            }
            if(i < n){
                st.push(idx);
            }
        }
        
        return result;
    }
};