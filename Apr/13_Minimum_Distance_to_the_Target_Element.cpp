// 1848. Minimum Distance to the Target Element
// Daily Challenge - 13/04/2026

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }

        return ans;
    }
};

// alternate solution
/* Finds answer faster in practice.
Stops early instead of scanning whole array.
Since we want minimum distance from start, expanding outwards guarantees first match is optimal.*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();

        for (int d = 0; d < n; d++) {
            if (start - d >= 0 && nums[start - d] == target) return d;
            if (start + d < n && nums[start + d] == target) return d;
        }

        return -1;
    }
};