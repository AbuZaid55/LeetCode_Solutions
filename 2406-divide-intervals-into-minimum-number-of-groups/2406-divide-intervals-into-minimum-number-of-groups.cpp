class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto& interval : intervals) {
            int left = interval[0];
            int right = interval[1];

            if (!pq.empty() && pq.top() < left) {
                pq.pop();
            }

            pq.push(right);
        }

        return pq.size();
    }
};