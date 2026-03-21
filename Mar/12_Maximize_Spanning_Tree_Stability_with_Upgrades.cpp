// 3600. Maximize Spanning Tree Stability with Upgrades
// Daily Challenge - 12/03/2026

class UnionFind {
public:
    vector<int> par, depth;
    int groups;

    UnionFind(int size) {
        par.resize(size);
        depth.assign(size, 0);
        iota(par.begin(), par.end(), 0);
        groups = size;
    }

    int getRoot(int node) {
        if (par[node] != node) par[node] = getRoot(par[node]);
        return par[node];
    }

    bool mergeSet(int a, int b) {
        a = getRoot(a);
        b = getRoot(b);

        if (a == b) return false;

        if (depth[a] < depth[b]) swap(a, b);
        par[b] = a;
        if (depth[a] == depth[b]) depth[a]++;

        groups--;
        return true;
    }
};

class Solution {
public:
    bool checkPossible(int nodes, vector<vector<int>>& conn, int limit, int val) {
        UnionFind uf(nodes);

        for (auto &it : conn) {
            int a = it[0], b = it[1], w = it[2], type = it[3];

            if (type == 1) {
                if (w < val) return false;
                if (!uf.mergeSet(a, b)) return false;
            }
        }

        for (auto &it : conn) {
            int a = it[0], b = it[1], w = it[2], type = it[3];

            if (type == 0 && w >= val) {
                uf.mergeSet(a, b);
            }
        }

        int upgrades = 0;

        for (auto &it : conn) {
            int a = it[0], b = it[1], w = it[2], type = it[3];

            if (type == 0 && w < val && 2 * w >= val) {
                if (uf.mergeSet(a, b)) {
                    upgrades++;
                    if (upgrades > limit) return false;
                }
            }
        }

        return uf.groups == 1;
    }

    int maxStability(int nodes, vector<vector<int>>& conn, int limit) {
        {
            UnionFind uf(nodes);
            for (auto &it : conn) {
                if (it[3] == 1) {
                    if (!uf.mergeSet(it[0], it[1])) return -1;
                }
            }
        }

        int left = 1, right = 200000, res = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (checkPossible(nodes, conn, limit, mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};