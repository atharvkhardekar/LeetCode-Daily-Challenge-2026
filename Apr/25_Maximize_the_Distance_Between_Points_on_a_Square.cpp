// 3464. Maximize the Distance Between Points on a Square
// Daily Challenge - 25/04/2026

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;

        for (auto &pt : points) {
            int x = pt[0], y = pt[1];

            if (x == 0) {
                pos.push_back(y);
            } 
            else if (y == side) {
                pos.push_back((long long)side + x);
            } 
            else if (x == side) {
                pos.push_back(3LL * side - y);
            } 
            else {
                pos.push_back(4LL * side - x);
            }
        }

        sort(pos.begin(), pos.end());

        auto canPlace = [&](int dist) {
            int n = pos.size();
            vector<int> indices(k);

            long long lastPos = pos[0];
            indices[0] = 0;

            for (int i = 1; i < k; i++) {
                auto it = lower_bound(pos.begin(), pos.end(), lastPos + dist);
                if (it == pos.end()) return false;

                indices[i] = it - pos.begin();
                lastPos = *it;
            }

            if (pos[indices[k - 1]] - pos[0] <= 4LL * side - dist) {
                return true;
            }

            for (indices[0] = 1; indices[0] < indices[1]; indices[0]++) {
                for (int i = 1; i < k; i++) {
                    while (indices[i] < n && 
                           pos[indices[i]] < pos[indices[i - 1]] + dist) {
                        indices[i]++;
                    }

                    if (indices[i] == n) return false;
                }

                if (pos[indices[k - 1]] - pos[indices[0]] <= 4LL * side - dist) {
                    return true;
                }
            }

            return false;
        };

        int low = 1;
        int high = (4LL * side) / k + 1;

        while (low + 1 < high) {
            int mid = low + (high - low) / 2;

            if (canPlace(mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
