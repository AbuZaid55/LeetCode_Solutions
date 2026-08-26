class Solution {
public:
    int myAtoi(string s) {

        int ptr = 0;
        int sign = 1;

        // 1. Skip leading spaces
        while (ptr < s.length() && s[ptr] == ' ') {
            ptr++;
        }

        // No characters left
        if (ptr == s.length()) {
            return 0;
        }

        // 2. Check sign
        if (s[ptr] == '-') {
            sign = -1;
            ptr++;
        }
        else if (s[ptr] == '+') {
            ptr++;
        }

        // 3. Convert digits
        long long num = 0;

        while (ptr < s.length() && isdigit(s[ptr])) {

            num = num * 10 + (s[ptr] - '0');

            // 4. Check overflow
            if (sign == 1 && num > INT_MAX) {
                return INT_MAX;
            }

            if (sign == -1 && -num < INT_MIN) {
                return INT_MIN;
            }

            ptr++;
        }

        return num * sign;
    }
};