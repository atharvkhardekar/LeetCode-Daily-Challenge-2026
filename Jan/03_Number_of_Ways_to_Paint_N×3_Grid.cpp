// 1411. Number of Ways to Paint N × 3 Grid
// Daily Challenge - 03/01/2026

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long a = 6; 
        long long b = 6; 

        for (int i = 2; i <= n; i++) {
            long long newA = (3 * a + 2 * b) % MOD;
            long long newB = (2 * a + 2 * b) % MOD;
            a = newA;
            b = newB;
        }

        return (a + b) % MOD;
    }
};