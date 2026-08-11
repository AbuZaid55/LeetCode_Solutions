class Solution {
public:
    int reverse(int x) {
        int reverse_num = 0;
        while(x != 0){
            int digit = x%10;
            x = x / 10;

            // === Check overflow ===
            if (reverse_num > INT_MAX / 10 ||
                (reverse_num == INT_MAX / 10 && digit > 7)) {
                return 0;
            }

            if (reverse_num < INT_MIN / 10 ||
                (reverse_num == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            reverse_num = reverse_num*10 +  digit;
        }
        return reverse_num;
    }
};