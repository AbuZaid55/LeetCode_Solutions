class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) {
            return {};
        }
        
        unordered_map<char, vector<string>> mp = {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}
        };

        vector<string> result =  mp[digits[0]];

        for(int i = 1;  i<digits.size(); i++){
                vector<string> current = mp[digits[i]];

                vector<string> temp;

                for(int j = 0; j<result.size(); j++){
                    for(int k = 0; k<current.size(); k++){
                        temp.push_back(result[j] + current[k]);
                    }
                }

                result = temp;
        }

        return result;
    }
};