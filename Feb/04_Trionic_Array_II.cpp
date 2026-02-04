// 3640. Trionic Array II
// Daily Challenge - 04/02/2026

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        const long long NEG = -(1LL << 62);
        int n = (int)nums.size();

        long long inc0 = nums[0];
        long long incGood = NEG;

        long long dp1 = NEG;
        long long dp2 = NEG;
        long long ans = NEG;

        for (int i = 1; i < n; i++) {
            long long a = nums[i];
            long long prev = nums[i - 1];

            long long newInc0 = a;
            long long newIncGood = NEG;

            if (prev < a) {
                newInc0 = max(inc0 + a, a);
                newIncGood = inc0 + a;
            }

            long long newDp1 = NEG;
            if (prev > a) {
                if (dp1 > NEG / 2) newDp1 = max(newDp1, dp1 + a);
                if (incGood > NEG / 2) newDp1 = max(newDp1, incGood + a);
            }

            long long newDp2 = NEG;
            if (prev < a) {
                if (dp2 > NEG / 2) newDp2 = max(newDp2, dp2 + a);
                if (dp1 > NEG / 2) newDp2 = max(newDp2, dp1 + a);
            }

            ans = max(ans, newDp2);

            inc0 = newInc0;
            incGood = newIncGood;
            dp1 = newDp1;
            dp2 = newDp2;
        }

        return ans;
    }
};