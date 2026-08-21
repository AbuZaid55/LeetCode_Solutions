class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }
        
        int left = 1;
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while(left < right){
            int mid = left + (right - left) / 2;

            int totalBouquets = 0;
            int adjacentFlowers = 0;

            for(int bloomD: bloomDay){
                if(bloomD<= mid){
                    adjacentFlowers++;
                    if(adjacentFlowers == k){
                        totalBouquets++;
                        adjacentFlowers = 0;
                    }
                }else{
                    adjacentFlowers = 0;
                }
            }

            if(totalBouquets >= m){
                right = mid;
            }else{
                left = mid + 1;
            }

        }

        return left;
    }
};