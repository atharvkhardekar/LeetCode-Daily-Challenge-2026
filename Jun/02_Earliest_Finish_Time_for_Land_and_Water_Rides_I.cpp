// 3633. Earliest Finish Time for Land and Water Rides I
// Daily Challenge - 02/06/2026

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int finish1 = max(landStartTime[i] + landDuration[i], waterStartTime[j]) + waterDuration[j];

                int finish2 = max(waterStartTime[j] + waterDuration[j], landStartTime[i]) + landDuration[i];

                ans = min({ans, finish1, finish2});
            }
        }

        return ans;
    }
};