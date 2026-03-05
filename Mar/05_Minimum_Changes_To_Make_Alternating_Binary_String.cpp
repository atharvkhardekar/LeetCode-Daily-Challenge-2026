// 1758. Minimum Changes To Make Alternating Binary String
// Daily Challenge - 05/03/2026

class Solution {
public:
    int minOperations(string s) {
        int mismatch = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != (i % 2 ? '1' : '0'))
                mismatch++;
        }

        return min(mismatch, (int)s.size() - mismatch);
    }
};