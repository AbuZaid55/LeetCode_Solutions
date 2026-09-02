class Solution {
public:

    const long long MOD = 1e9 + 7;

    long long power(long long x, long long n){
        long long ans = 1;
        while(n>0){
            if(n % 2 == 1){
                ans = (ans * x) % MOD;
            }

            x = (x*x) % MOD;
            n = n/2;
        }

        return ans % MOD;
    }
    int countGoodNumbers(long long n) {

        long long totalOddPlaces = n/2;
        long long totalEvenPlaces = n - totalOddPlaces;

        long long a = power(5,totalEvenPlaces);
        long long b = power(4, totalOddPlaces);

        return (a * b) % MOD;
    }
};