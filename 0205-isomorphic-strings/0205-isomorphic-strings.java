class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] st = new int[256];
        int[] ts = new int[256];

        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i);
            char b = t.charAt(i);

            if (st[a] != ts[b]) {
                return false;
            }

            st[a] = i + 1;
            ts[b] = i + 1;
        }

        return true;
    }
}