// 1722. Minimize Hamming Distance After Swap Operations
// Daily Challenge - 21/04/2026

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return;

        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else if (rank[pb] < rank[pa]) {
            parent[pb] = pa;
        } else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);

        for (auto &e : allowedSwaps) {
            dsu.unite(e[0], e[1]);
        }

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[dsu.find(i)].push_back(i);
        }

        int ans = 0;

        for (auto &g : groups) {
            unordered_map<int, int> freq;

            for (int idx : g.second) {
                freq[source[idx]]++;
            }

            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++;
                }
            }
        }

        return ans;
    }
};