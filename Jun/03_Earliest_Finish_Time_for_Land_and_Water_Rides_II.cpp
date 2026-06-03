// 3635. Earliest Finish Time for Land and Water Rides II
// Daily Challenge - 03/06/2026

class Solution {
public:
    long long solveQuery(long long t,
                         const vector<int>& start,
                         const vector<int>& prefMinDur,
                         const vector<long long>& suffMinFinish) {
        
        int n = start.size();
        int pos = upper_bound(start.begin(), start.end(), t) - start.begin();

        long long ans = LLONG_MAX;

        if (pos > 0) {
            ans = min(ans, t + prefMinDur[pos - 1]);
        }

        if (pos < n) {
            ans = min(ans, suffMinFinish[pos]);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int,int>> water;
        for (int i = 0; i < m; i++) {
            water.push_back({waterStartTime[i], waterDuration[i]});
        }
        sort(water.begin(), water.end());

        vector<int> wStart(m), wPrefMinDur(m);
        vector<long long> wSuffMinFinish(m);

        for (int i = 0; i < m; i++) {
            wStart[i] = water[i].first;
            wPrefMinDur[i] = water[i].second;
            if (i) {
                wPrefMinDur[i] = min(wPrefMinDur[i], wPrefMinDur[i - 1]);
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            long long val = 1LL * water[i].first + water[i].second;
            if (i == m - 1) wSuffMinFinish[i] = val;
            else wSuffMinFinish[i] = min(val, wSuffMinFinish[i + 1]);
        }

        vector<pair<int,int>> land;
        for (int i = 0; i < n; i++) {
            land.push_back({landStartTime[i], landDuration[i]});
        }
        sort(land.begin(), land.end());

        vector<int> lStart(n), lPrefMinDur(n);
        vector<long long> lSuffMinFinish(n);

        for (int i = 0; i < n; i++) {
            lStart[i] = land[i].first;
            lPrefMinDur[i] = land[i].second;
            if (i) {
                lPrefMinDur[i] = min(lPrefMinDur[i], lPrefMinDur[i - 1]);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            long long val = 1LL * land[i].first + land[i].second;
            if (i == n - 1) lSuffMinFinish[i] = val;
            else lSuffMinFinish[i] = min(val, lSuffMinFinish[i + 1]);
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            long long landFinish = 1LL * landStartTime[i] + landDuration[i];

            ans = min(ans,
                      solveQuery(landFinish,
                                 wStart,
                                 wPrefMinDur,
                                 wSuffMinFinish));
        }

        for (int j = 0; j < m; j++) {
            long long waterFinish = 1LL * waterStartTime[j] + waterDuration[j];

            ans = min(ans,
                      solveQuery(waterFinish,
                                 lStart,
                                 lPrefMinDur,
                                 lSuffMinFinish));
        }

        return (int)ans;
    }
};