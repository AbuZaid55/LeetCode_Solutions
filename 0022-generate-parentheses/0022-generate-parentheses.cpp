class Solution {
public:
    void genParenthesis(string s, int openCount, int closeCount, vector<string>& arr, int n){
        if(openCount == n && closeCount == n){
            arr.push_back(s);
            return;
        }
        if(openCount < n){
            genParenthesis(s + "(", openCount + 1,closeCount,arr, n);
        }
        if(closeCount < openCount){
            genParenthesis(s + ")",openCount,closeCount + 1,arr, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> arr;
        genParenthesis("",0,0,arr, n);
        return arr;
    }
};