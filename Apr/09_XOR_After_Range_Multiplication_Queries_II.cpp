// 3655. XOR After Range Multiplication Queries I
// Daily Challenge - 09/04/2026

class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long fastPower(long long base, long long exp) {
        long long result = 1;
        while (exp) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    long long inverse(long long x) {
        return fastPower(x, MOD - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int threshold = sqrt(n);

        unordered_map<int, vector<vector<int>>> groups;

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], val = q[3];

            if (k >= threshold) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * val) % MOD;
                }
            } else {
                groups[k].push_back(q);
            }
        }

        for (auto &entry : groups) {
            int step = entry.first;
            auto &qs = entry.second;

            vector<long long> mult(n, 1);

            for (auto &q : qs) {
                int l = q[0], r = q[1], val = q[3];

                mult[l] = (mult[l] * val) % MOD;

                int cnt = (r - l) / step;
                int nxt = l + (cnt + 1) * step;

                if (nxt < n) {
                    mult[nxt] = (mult[nxt] * inverse(val)) % MOD;
                }
            }

            for (int i = 0; i < n; i++) {
                if (i >= step) {
                    mult[i] = (mult[i] * mult[i - step]) % MOD;
                }
                nums[i] = (1LL * nums[i] * mult[i]) % MOD;
            }
        }

        int result = 0;
        for (int x : nums) {
            result ^= x;
        }

        return result;
    }
};