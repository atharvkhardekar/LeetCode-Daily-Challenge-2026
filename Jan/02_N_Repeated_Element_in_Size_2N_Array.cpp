// 961. N-Repeated Element in Size 2N Array
// Daily Challenge - 02/01/2026

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for (int x : nums) {
            if (s.count(x))
                return x;
            s.insert(x);
        }
        return -1; 
    }
};