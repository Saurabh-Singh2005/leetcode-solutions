class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        int total_n = n + k - 1;
        int total_r = 2 * k;
        
        
        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };
        
        auto modInverse = [&](long long n) {
            return power(n, MOD - 2);
        };
        
        long long num = 1, den = 1;
        for (int i = 1; i <= total_r; i++) {
            num = (num * (total_n - i + 1)) % MOD;
            den = (den * i) % MOD;
        }
        
        return (num * modInverse(den)) % MOD;
    }
};