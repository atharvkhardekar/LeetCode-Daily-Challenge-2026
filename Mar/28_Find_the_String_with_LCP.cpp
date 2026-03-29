// 2573. Find the String with LCP
// Daily Challenge - 28/03/2026

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '#');

        char curr = 'a';

        for (int i = 0; i < n; i++) {
            if (s[i] == '#') {
                if (curr > 'z') return "";

                for (int j = i; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        s[j] = curr;
                    }
                }
                curr++;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 0;
                }

                if (dp[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }

        return s;
    }
};