// 3130. Find All Possible Stable Binary Arrays II
// Daily Challenge - 10/03/2026

class Solution {
public:
    static const int MOD = 1000000007;
    static const int MAXN = 1000;

    long long fact[MAXN + 1];
    long long invfact[MAXN + 1];

    long long modinv(long long n) {
        long long x = 0, y = 1, px = 1, py = 0;
        long long m = MOD;

        while (m != 0) {
            long long q = n / m;
            long long temp = m;
            m = n % m;
            n = temp;

            long long tx = x;
            x = px - q * x;
            px = tx;

            long long ty = y;
            y = py - q * y;
            py = ty;
        }
        return (px % MOD + MOD) % MOD;
    }

    void init() {
        fact[0] = 1;
        for (int i = 1; i <= MAXN; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        invfact[MAXN] = modinv(fact[MAXN]);

        for (int i = MAXN; i > 0; i--) {
            invfact[i - 1] = (invfact[i] * i) % MOD;
        }
    }

    long long ncr(int n, int r) {
        if (r < 0 || r > n) return 0;
        long long num = fact[n];
        long long den = (invfact[r] * invfact[n - r]) % MOD;
        return (num * den) % MOD;
    }

    long long splitways(int n, int k, int limit) {
        long long total = 0;
        int flag = 1;
        int remaining = n;

        for (int j = 0; j <= k && k <= remaining; j++) {
            long long term = (ncr(k, j) * ncr(remaining - 1, k - 1)) % MOD;

            total = (total + flag * term) % MOD;
            total = (total + MOD) % MOD;

            flag = -flag;
            remaining -= limit;
        }

        return total;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        init();

        long long result = 0;

        int start = (min(zero, one) + limit - 1) / limit;

        long long prev = 0;
        long long curr = splitways(one, start, limit);
        long long next = splitways(one, start + 1, limit);

        for (int k = start; k <= zero; k++) {
            long long choices =
                ((prev + 2 * curr + next) % MOD *
                 splitways(zero, k, limit)) % MOD;

            result = (result + choices) % MOD;

            prev = curr;
            curr = next;
            next = splitways(one, k + 2, limit);
        }

        return result;
    }
};