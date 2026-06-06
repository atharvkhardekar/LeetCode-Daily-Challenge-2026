// 2574. Left and Right Sum Differences
// Daily Challenge - 06/06/2026

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            ans[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }

        return ans;
    }
};