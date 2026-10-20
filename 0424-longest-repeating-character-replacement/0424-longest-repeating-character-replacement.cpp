
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxCount = 0;
        int maxFreq = 0;

        vector<int> freq(26, 0);

        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxCount = max(maxCount, right - left + 1);
        }

        return maxCount;
    }
};
