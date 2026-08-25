class Solution {
    public boolean rotateString(String s, String goal) {

        if (s.length() != goal.length()) {
            return false;
        }

        for(int i = 0; i<s.length(); i++){
            boolean match = true;

            for(int j = 0; j<s.length(); j++){
                
                if(s.charAt((i + j) % s.length()) != goal.charAt(j)){
                    match  = false;
                    break;
                }
            }

            if(match){
                return true;
            }
        }

        return false;
    }
}