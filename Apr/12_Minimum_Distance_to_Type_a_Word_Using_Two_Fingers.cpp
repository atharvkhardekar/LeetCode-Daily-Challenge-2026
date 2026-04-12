// 1320. Minimum Distance to Type a Word Using Two Fingers
// Daily Challenge - 12/04/2026

int dp[300][27];

class Solution {
public:
    static inline int dist(int a, int b) {
        if (a == 26 || b == 26) return 0;
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    static int minimumDistance(string& word) {
        int n = word.size();
        const int INF = 1e9 + 7;

        fill(&dp[0][0], &dp[0][0] + n * 27, INF);

        dp[0][26] = 0;

        int last = word[0] - 'A';

        for (int i = 1; i < n; i++) {
            int curr = word[i] - 'A';

            for (int k = 0; k < 27; k++) {
                if (dp[i - 1][k] >= INF) continue;

                dp[i][k] = min(dp[i][k], dp[i - 1][k] + dist(last, curr));

                dp[i][last] = min(dp[i][last], dp[i - 1][k] + dist(k, curr));
            }

            last = curr;
        }

        return *min_element(dp[n - 1], dp[n - 1] + 27);
    }
};