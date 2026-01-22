// 3507. Minimum Pair Removal to Sort Array I
// Daily Challenge - 22/01/2026

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (!isSorted(nums)) {
            int minSum = INT_MAX;
            int idx = 0;

            for (int i = 0; i + 1 < nums.size(); i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            ops++;
        }

        return ops;
    }

private:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
};
