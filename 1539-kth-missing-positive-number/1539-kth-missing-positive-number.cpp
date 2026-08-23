class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int total_missing = arr[0] - 1;
        if(total_missing >= k){
            return k;
        }

        int ptr = 0;
        while(ptr < arr.size() - 1){
            int gap = arr[ptr + 1] - arr[ptr] - 1;
            if(gap > 0){
                total_missing += gap;
                if(total_missing >=k){
                    int need = k - (total_missing - gap);
                    return arr[ptr] + need;
                }
            }
            ptr ++;
        }

        int need = k - total_missing;
        return arr[ptr] + need;
    }
};