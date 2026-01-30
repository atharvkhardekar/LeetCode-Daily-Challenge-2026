// 2977. Minimum Cost to Convert String II
// Daily Challenge - 30/01/2026

class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;
        int n = source.size();

        unordered_map<string, int> id;
        vector<string> all;
        auto getId = [&](string s) {
            if (!id.count(s)) {
                id[s] = all.size();
                all.push_back(s);
            }
            return id[s];
        };

        for (int i = 0; i < original.size(); i++) {
            getId(original[i]);
            getId(changed[i]);
        }

        int m = all.size();

        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        for (int i = 0; i < m; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < m; k++)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            for (int k = 0; k < m; k++) {
                int len = all[k].size();
                if (i + len > n) continue;

                if (source.substr(i, len) != all[k]) continue;

                for (int j = 0; j < m; j++) {
                    if (dist[k][j] == INF) continue;
                    if (target.substr(i, len) == all[j]) {
                        dp[i] = min(dp[i], dist[k][j] + dp[i + len]);
                    }
                }
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};