class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> rFreq(128, 0);
        vector<int> wFreq(128, 0);

        for(char c: t){
            rFreq[c]++;
        }

        int required = 0;
        for(int i = 0; i<128; i++){
            if(rFreq[i] > 0){
                required++;
            }
        }

        int formed = 0;
        int left = 0; 
        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right<s.length(); right++){
            char c = s[right];
            wFreq[c]++;

            if(rFreq[c] > 0 && rFreq[c] == wFreq[c]){
                formed++;
            }

            while(formed == required){
                int len = right - left + 1;
                if(len < minLen){
                    minLen = len;
                    start = left;
                }

                char leftChar = s[left];
                wFreq[leftChar]--;
                left++;

                if(rFreq[leftChar] > 0 && wFreq[leftChar] < rFreq[leftChar]){
                    formed--;
                }
            }
        }

        if(minLen == INT_MAX){
            return "";
        }

        return s.substr(start, minLen);
    }
};