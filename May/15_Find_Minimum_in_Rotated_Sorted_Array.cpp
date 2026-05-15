// 153. Find Minimum in Rotated Sorted Array
// Daily Challenge - 15/05/2026

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
         
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};
