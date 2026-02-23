// 1461. Check If a String Contains All Binary Codes of Size K
// Daily Challenge - 23/02/2026

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int total = 1 << k;   
        
        if (n < k + total - 1) return false;

        vector<bool> seen(total, false);
        int mask = 0;
        int found = 0;

        for (int i = 0; i < n; i++) {
            mask = ((mask << 1) & (total - 1)) | (s[i] - '0');

            if (i >= k - 1) {
                if (!seen[mask]) {
                    seen[mask] = true;
                    found++;
                    if (found == total) return true;
                }
            }
        }

        return false;
    }
};