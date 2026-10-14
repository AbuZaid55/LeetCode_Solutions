class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candyList(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candyList[i] = candyList[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyList[i] = max(candyList[i], candyList[i + 1] + 1);
            }
        }

        int minCandy = 0;
        for (int c : candyList) {
            minCandy += c;
        }

        return minCandy;
    }
};