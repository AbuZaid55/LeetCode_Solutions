class Solution {
public:
    void solve(int pos, long long current, long long previous,
               string expr, string num, int target,
               vector<string>& ans) {

        // All digits used
        if (pos == num.size()) {
            if (current == target)
                ans.push_back(expr);
            return;
        }

        // Try taking 1 digit, 2 digits, 3 digits...
        for (int i = pos; i < num.size(); i++) {

            // Don't allow numbers like 05
            if (i > pos && num[pos] == '0')
                break;

            string part = num.substr(pos, i - pos + 1);
            long long x = stoll(part);

            // First number
            if (pos == 0) {
                solve(i + 1, x, x, part, num, target, ans);
            }
            else {

                // +
                solve(i + 1,
                      current + x,
                      x,
                      expr + "+" + part,
                      num, target, ans);

                // -
                solve(i + 1,
                      current - x,
                      -x,
                      expr + "-" + part,
                      num, target, ans);

                // *
                solve(i + 1,
                      current - previous + previous * x,
                      previous * x,
                      expr + "*" + part,
                      num, target, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        vector<string> ans;

        solve(0, 0, 0, "", num, target, ans);

        return ans;
    }
};