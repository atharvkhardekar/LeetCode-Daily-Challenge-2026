// 868. Binary Gap
// Daily Challenge - 22/02/2026

class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;   
        int pos = 0;    
        int ans = 0;

        while (n > 0) {
            if (n & 1) {
                if (prev != -1) {
                    ans = max(ans, pos - prev);
                }
                prev = pos;
            }
            n >>= 1;
            pos++;
        }

        return ans;
    }
};