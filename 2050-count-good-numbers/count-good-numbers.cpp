class Solution {
public:
    const int MOD = 1000000007;

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
                exp--;
            } else {
                base = (base * base) % mod;
                exp /= 2;
            }
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long odd_idx = n / 2;
        long long even_idx = (n % 2 == 0) ? odd_idx : odd_idx + 1;

        long long ans = (modPow(5, even_idx, MOD) * modPow(4, odd_idx, MOD)) % MOD;

        return ans;
    }
};
