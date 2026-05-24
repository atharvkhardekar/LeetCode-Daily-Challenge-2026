// 1340. Jump Game V
// Daily Challenge - 24/05/2026

class Solution {
public:
    int solve(int index, vector<int>& nums, int limit, vector<int>& memo) {

        if (memo[index] != -1) {
            return memo[index];
        }

        int n = nums.size();
        int maxSteps = 1;

        for (int j = index + 1; j <= min(n - 1, index + limit); j++) {

            if (nums[j] >= nums[index]) {
                break;
            }

            maxSteps = max(maxSteps, 1 + solve(j, nums, limit, memo));
        }

        for (int j = index - 1; j >= max(0, index - limit); j--) {

            if (nums[j] >= nums[index]) {
                break;
            }

            maxSteps = max(maxSteps, 1 + solve(j, nums, limit, memo));
        }

        return memo[index] = maxSteps;
    }

    int maxJumps(vector<int>& arr, int d) {

        int size = arr.size();
        vector<int> memo(size, -1);

        int result = 1;

        for (int i = 0; i < size; i++) {
            result = max(result, solve(i, arr, d, memo));
        }

        return result;
    }
};
