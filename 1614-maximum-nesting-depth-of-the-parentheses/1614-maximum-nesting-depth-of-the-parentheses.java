class Solution {
    public int maxDepth(String s) {
        int maxDepth = 0;
        int depth = 0;
        for(char c: s.toCharArray()){
            if(c == '('){
                depth++;
            }else if(c == ')'){
                depth --;
            }

            if(depth > maxDepth){
                maxDepth = depth;
            }
        }

        return maxDepth;
    }
}