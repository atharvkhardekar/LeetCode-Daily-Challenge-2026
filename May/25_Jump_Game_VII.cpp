// 1871. Jump Game VII
// Daily Challenge - 25/05/2026

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int n = s.size();

        vector<bool> reachable(n, false);
        reachable[0] = true;

        int validCount = 0;

        for (int i = 1; i < n; i++) {

            if (i - minJump >= 0 && reachable[i - minJump]) {
                validCount++;
            }

            if (i - maxJump - 1 >= 0 && reachable[i - maxJump - 1]) {
                validCount--;
            }

            if (s[i] == '0' && validCount > 0) {
                reachable[i] = true;
            }
        }

        return reachable[n - 1];
    }
};