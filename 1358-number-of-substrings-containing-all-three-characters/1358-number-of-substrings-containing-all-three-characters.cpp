
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left = 0;
        int count = 0;
        int formed = 0;

        vector<int> freq(3, 0);

        for (int right = 0; right < n; right++) {
            char c = s[right];
            freq[c - 'a']++;

            if (freq[c - 'a'] == 1) {
                formed++;
            }

            while (formed == 3) {
                count += n - right;

                char leftChar = s[left];
                freq[leftChar - 'a']--;

                if (freq[leftChar - 'a'] == 0) {
                    formed--;
                }

                left++;
            }
        }

        return count;
    }
};
