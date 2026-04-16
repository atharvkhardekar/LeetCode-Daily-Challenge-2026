// 3488. Closest Equal Element Queries
// Daily Challenge - 16/04/2026

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for (int q : queries) {
            int val = nums[q];
            auto &vec = mp[val];
            
            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            auto it = lower_bound(vec.begin(), vec.end(), q);
            int idx = it - vec.begin();
            
            int res = INT_MAX;
            
            int nextIdx = vec[(idx + 1) % vec.size()];
            int d1 = abs(nextIdx - q);
            res = min(res, min(d1, n - d1));
            
            int prevIdx = vec[(idx - 1 + vec.size()) % vec.size()];
            int d2 = abs(prevIdx - q);
            res = min(res, min(d2, n - d2));
            
            ans.push_back(res);
        }
        
        return ans;
    }
};