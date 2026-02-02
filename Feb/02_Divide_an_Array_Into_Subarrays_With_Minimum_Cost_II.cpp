// 3013. Divide an Array Into Subarrays With Minimum Cost II
// Daily Challenge - 02/02/2026

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int m = k - 1;
        long long current_sum = 0;
        multiset<int> left, right;

        auto balance = [&]() {
            while (left.size() < m && !right.empty()) {
                int val = *right.begin();
                current_sum += val;
                left.insert(val);
                right.erase(right.find(val));
            }
            while (left.size() > m) {
                int val = *left.rbegin();
                current_sum -= val;
                right.insert(val);
                left.erase(prev(left.end()));
            }
        };

        for (int i = 1; i <= dist + 1; ++i) {
            right.insert(nums[i]);
        }
        balance();

        long long min_sum = current_sum;

        for (int i = 2; i <= n - dist - 1; ++i) {
            int out_val = nums[i - 1];
            auto it = left.find(out_val);
            if (it != left.end()) {
                current_sum -= out_val;
                left.erase(it);
            } else {
                right.erase(right.find(out_val));
            }

            right.insert(nums[i + dist]);
            
            if (!left.empty() && *left.rbegin() > *right.begin()) {
                int l_val = *left.rbegin();
                int r_val = *right.begin();
                current_sum = current_sum - l_val + r_val;
                left.erase(prev(left.end()));
                right.erase(right.begin());
                left.insert(r_val);
                right.insert(l_val);
            }

            balance();
            min_sum = min(min_sum, current_sum);
        }

        return min_sum + nums[0];
    }
};
