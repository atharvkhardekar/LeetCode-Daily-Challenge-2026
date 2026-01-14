// 3454. Separate Squares II
// Daily Challenge - 14/01/2026

class SegmentTree {
public:
    int n;
    vector<int> cnt;
    vector<long long> coverLen;
    vector<long long> xs;

    SegmentTree(const vector<long long>& coords) {
        xs = coords;
        n = xs.size() - 1;
        cnt.assign(4 * n, 0);
        coverLen.assign(4 * n, 0);
    }

    void update(int idx, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            cnt[idx] += val;
        } else {
            int mid = (l + r) / 2;
            update(idx*2, l, mid, ql, qr, val);
            update(idx*2+1, mid, r, ql, qr, val);
        }
        if (cnt[idx] > 0) {
            coverLen[idx] = xs[r] - xs[l];
        } else if (l + 1 == r) {
            coverLen[idx] = 0;
        } else {
            coverLen[idx] = coverLen[idx*2] + coverLen[idx*2+1];
        }
    }

    long long totalCovered() {
        return coverLen[1];
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        vector<tuple<long long,int,long long,long long>> events;
        vector<long long> coordX;

        for (auto &sq : squares) {
            long long x = sq[0], y = sq[1], l = sq[2];
            events.emplace_back(y, +1, x, x + l);
            events.emplace_back(y + l, -1, x, x + l);
            coordX.push_back(x);
            coordX.push_back(x + l);
        }

        sort(coordX.begin(), coordX.end());
        coordX.erase(unique(coordX.begin(), coordX.end()), coordX.end());
        sort(events.begin(), events.end());

        SegmentTree seg(coordX);
        long long prevY = get<0>(events[0]);
        long long totalArea = 0;
        for (auto &ev : events) {
            auto [curY, delta, xl, xr] = ev;
            long long h = curY - prevY;
            if (h > 0)
                totalArea += seg.totalCovered() * h;
            int L = lower_bound(coordX.begin(), coordX.end(), xl) - coordX.begin();
            int R = lower_bound(coordX.begin(), coordX.end(), xr) - coordX.begin();
            seg.update(1, 0, seg.n, L, R, delta);
            prevY = curY;
        }

        double halfArea = totalArea / 2.0;

        SegmentTree seg2(coordX);
        prevY = get<0>(events[0]);
        long double accArea = 0;

        for (auto &ev : events) {
            auto [curY, delta, xl, xr] = ev;
            long long h = curY - prevY;
            long long width = seg2.totalCovered();
            if (h > 0 && accArea + (long double)width * h >= halfArea) {
                long double need = halfArea - accArea;
                return prevY + need / width;
            }
            accArea += (long double)width * h;

            int L = lower_bound(coordX.begin(), coordX.end(), xl) - coordX.begin();
            int R = lower_bound(coordX.begin(), coordX.end(), xr) - coordX.begin();
            seg2.update(1, 0, seg2.n, L, R, delta);
            prevY = curY;
        }

        return prevY;
    }
};
