// 3315. Construct the Minimum Bitwise Array II
// Daily Challenge - 21/01/2026

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int n : nums) {
            if ((n & (n - 1)) == 0) {
                ans.push_back(-1);
                continue;
            }

            int k = 0;
            int temp = n;

            while (temp & 1) {
                k++;
                temp >>= 1;
            }

            int x = n - (1 << (k - 1));
            ans.push_back(x);
        }

        return ans;
    }
};