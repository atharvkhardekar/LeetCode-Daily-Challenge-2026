// 3761. Minimum Absolute Distance Between Mirror Pairs
// Daily Challenge - 17/04/2026

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> last_seen;
        int min_dist = INT_MAX;
        bool found = false;

        for (int j = 0; j < n; ++j) {
            
            int current_val = nums[j];
            
            if (last_seen.count(current_val)) {
                min_dist = min(min_dist, j - last_seen[current_val]);
                found = true;
            }
            
            int rev_i = reverseInt(current_val);
            last_seen[rev_i] = j;
        }

        return found ? min_dist : -1;
    }

private:
    int reverseInt(int n) {
        long rev = 0; 
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return (int)rev;
    }
};
