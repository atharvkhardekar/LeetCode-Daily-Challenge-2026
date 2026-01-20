// 3314. Construct the Minimum Bitwise Array I
// Daily Challenge - 20/01/2026

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            for (int x = 0; x <= nums[i]; x++) {
                if ((x | (x + 1)) == nums[i]) {
                    ans[i] = x;
                    break; 
                }
            }
        }

        return ans;
    }
};