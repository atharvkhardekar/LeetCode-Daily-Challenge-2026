// 396. Rotate Function
// Daily Challenge - 01/05/2026

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int n = nums.size();

        long long sum = 0;
        long long f0 = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f0 += 1LL * i * nums[i];
        }

        long long ans = f0;
        long long curr = f0;

        for (int k = 1; k < n; k++) {

            curr = curr + sum - 1LL * n * nums[n - k];

            ans = max(ans, curr);
        }

        return (int)ans;
    }
};