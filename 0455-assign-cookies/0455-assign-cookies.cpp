class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ptrG = 0;
        int ptrS = 0;

        int happay = 0;

        while(ptrG < g.size() && ptrS < s.size()){
            if(s[ptrS] >= g[ptrG]){
                happay++;
                ptrG++;
                ptrS++;
            }else if(s[ptrS] < g[ptrG]){
                ptrS++;
            }
        }

        return happay;
    }
};