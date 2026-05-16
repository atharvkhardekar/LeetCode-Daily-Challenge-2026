// 154. Find Minimum in Rotated Sorted Array II
// Daily Challenge - 16/05/2026

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size() - 1;
        int target = nums[size];

        int start = 0;
        int end = size;

        while (start < size && nums[start] == target) {
            start++;
        }

        while (start < end) {
            int middle = start + (end - start) / 2;

            if (nums[middle] > target) {
                start = middle + 1;
            } else {
                end = middle;
            }
        }

        return nums[start];
    }
};