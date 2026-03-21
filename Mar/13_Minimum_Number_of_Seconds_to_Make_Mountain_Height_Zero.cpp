// 3296. Minimum Number of Seconds to Make Mountain Height Zero
// Daily Challenge - 13/03/2026

class Solution {
public:
    long long maxHeight(long long T, int t) {
        long long val = (long long)(sqrt(1.0 + 8.0 * T / t) - 1) / 2;
        return val;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0, r = 1e18;
        long long ans = r;

        while (l <= r) {
            long long mid = (l + r) / 2;

            long long removed = 0;

            for (int t : workerTimes) {
                removed += maxHeight(mid, t);
                if (removed >= mountainHeight) break;
            }

            if (removed >= mountainHeight) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
