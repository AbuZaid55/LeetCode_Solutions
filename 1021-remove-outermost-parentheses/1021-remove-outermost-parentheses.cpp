class Solution {
public:
    string removeOuterParentheses(string s) {
        int openParen = 0;
        int closeParen = 0;
        string sub = "";
        string newString = "";

        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                openParen++;
            }else if(s[i] == ')'){
                closeParen++;
            }

            sub += s[i];

            if(openParen == closeParen){
                sub.erase(sub.begin());
                sub.pop_back();

                newString += sub;
                sub = "";
                openParen = 0;
                closeParen = 0;
            }
        }

        return newString;
    }
};